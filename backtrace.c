//it prints  a list of the function calls on the stack above the point at which the error occurred. 


void _backtrace(uint64 fp)
{
  if((PGROUNDUP(fp) <= fp) || (PGROUNDDOWN(fp) > fp))
    return;
  printf("%p\n", *((uint64 *)fp-1));
 // printf("p== %p\n", fp);
  _backtrace(*((uint64 *)(fp)-2));
}
void
backtrace(void)
{
  printf("backtrace:\n");
   uint64 p = r_fp();
  if((PGROUNDUP(p) < p) || (PGROUNDDOWN(p) > p))
    return;

  
  printf("%p\n", *((uint64 *)(p)-1));

  _backtrace(*((uint64 *)(p)-2));
}
