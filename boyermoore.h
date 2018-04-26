#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <stdio.h>

/*
 * @strfind
 *   Search string from a source string via BoyerMoore algorithm
 *
 * @pSrc
 *   The source string
 * @pSearch
 *   The search string, search this string from *pSrc
 *
 * @return
 *   Return -1 if *pSearch not found, else return the index that
 *   found at.
 */
int strfind(const char *pSrc, const char *pSearch);

#endif /* End of _MYSTRING_H_ */
