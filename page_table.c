#print page table for process



void vmprint(pagetable_t pagetable, int deep)
{
	if(deep == 1)
		printf("page table %p\n", pagetable);
  for(int i = 0; i < 512; i++)
  {
	pte_t pte = pagetable[i];
	if(pte & PTE_V){
    switch (deep)
    {
     case 1: printf("..%d: pte %x pa %p\n", i, pte, PTE2PA(pte));
       break;
     case 2: printf(".. ..%d: pte %x pa %p\n", i, pte, PTE2PA(pte));
      break;
     case 3: printf(".. .. ..%d: pte %x pa %p\n", i, pte, PTE2PA(pte));
      break;
    }
		if(deep != 3)
			vmprint((pagetable_t)(PTE2PA(pte)), deep+1);
	}
	}
}
