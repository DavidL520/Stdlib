/*****************************************************************
 *
 *  implementation of SAC standard library module Bits
 *
 *****************************************************************/

int SAC_Bits_BitRotateRight(int k, int val)
{
  return( (val >> k) + (val<<(sizeof(int)-1)));
}

/*****************************************************************/
