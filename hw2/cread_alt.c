//I use gcc -O -S to compile the program, and there is no jump
long cread(long *xp){
  long zero = 0;
  return *(xp ? xp : &zero);
}
