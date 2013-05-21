#include <mm/pmm.h>

typedef struct mem_chunk
{
	mem_chunk *next;
	mem_chunk *prev;
}mem_chunk_t;

mem_chunk_t **curr, **prev;
rhkbool out_of_memory;

void pmm_init(multiboot_info_t *mbi)
{
	multiboot_memory_map_t *mmap = mbi->mmap_addr;
	uint64_t start,end;
	while(mmap < mbi->mmap_addr + mbi->mmap_len)
	{
		if(mmap->type > 4)
		{
			mmap->type = 1;
		}
		
		if(mmap->type = MULTIBOOT_MEMORY_AVAILABLE)
		{
			start 	= mmap->addr;
			end   	= start + mmap->len;
			start	= (start + 0x00000FFF) & 0xFFFFFFFFFFFFF000;
			end 	= end & 0xFFFFFFFFFFFFF000;
			for(; start < end; start += 0x00001000)
			{
				pmm_free(start);
			}
		}
		mmap = (multiboot_memory_map_t*)( (uint32_t)mmap + mmap->size + sizeof(uint32_t));
	}
}
uint32_t* pmm_alloc()
{
	if(out_of_memory)
	{
		panic("Out of memory!");
		return 0;
	}
	
	uint32_t *tmp;
	if((*curr)->prev == NULL)
	{
		out_of_memory = TRUE;
		*curr = NULL;
		tmp = (uint32_t*)(*(*curr));
		curr = NULL;
	}
	else
	{
		*curr = NULL;
		tmp = (uint32_t*)(*(*curr));
		(*prev)->next = NULL;
		curr = prev;
		prev = &((*prev)->prev);
	}
	
	return tmp;
}
void pmm_free(uint64_t *addr)
{
	mem_chunk_t *tmp = (mem_chunk_t*)addr;
	if((*prev) == NULL && (*curr) == NULL)
	{
		*curr = *prev = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	else
	{
		(*curr)->next = tmp;
		prev = curr;
		*curr = tmp;
		tmp->prev = *prev;
	}
	
	if(!vmm_isMapped(addr))
	{
		vmm_map(addr, VMM_PAGE_VAL(addr, PAGE_PRESENT|PAGE_WRITE));
	}
}
