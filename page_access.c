
//a system call that reports which pages have been accessed


int
sys_pgaccess(void)
{
  int test = 0;
  uint64 bits;
  int num;
  pte_t *addr;
  uint64 page;
  pagetable_t pt = myproc()->pagetable;
   if(argint(1, &num) < 0)
    return -1;
   if(argaddr(0, &page) < 0)
    return -1;
   if(argaddr(2, &bits) < 0)
    return -1;
   for(int i = 0; i < num; i++){
  //   printf("%d", i+1);
   addr = walk(pt, page + PGSIZE*i, 0);

    if((*addr & PTE_A) != 0){
      test = (test | (1  << i));
      *addr = *addr & ~(PTE_A);
 //     printf("%d", i);
    }
   }
   copyout(pt, bits, (char *)&test, sizeof(test));
  return 0;
}
