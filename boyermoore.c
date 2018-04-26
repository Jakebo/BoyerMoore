#include <string.h>
#include "boyermoore.h"

/*
 * @badcharrule
 *   Return the steps forware according bad char rule:
 *     - If this char was in the search string, return
 *       (offset - x), 'x' was the first position of
 *       back forware releate to offset
 *     - If this char isn't in the search string,
 *       return (offset - (-1))
 *
 * @pSearch:
 *   The search string
 * @badchar:
 *   The bad char in the source string with mismatch
 *   the search string
 * offset:
 *   The current offset of *pSearch
 *
 * return:
 *   Return the steps with search string need to forward
 */
static int badcharrule(const char *pSearch, const char badchar, const int offset)
{
    for (int index = offset - 1; index > -1; --index) {
        if (pSearch[index] == badchar)
            return (offset - index);
    }

    return (offset - (-1));
}

/*
 * @displaycurstate
 *   Display the cureet progress of searching
 *
 * @pSrc:
 *   The source string
 * @pSearch:
 *   The search string
 * @offset:
 *   The current offset of *pSrc
 */
static void displaycurstate(const char *pSrc, const char *pSearch, const int offset)
{
    printf("%s\n", pSrc);

    for (int i = 0; i < (offset - (strlen(pSearch) - 1)); ++i)
        printf("-");

    printf("%s\n\n", pSearch);

    return;
}

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
int strfind(const char *pSrc, const char *pSearch)
{
    int srcEndOffset = strlen(pSrc) - 1;    // End offset of *pSrc
    int seaEndOffset = strlen(pSearch) - 1; // End offset of *pSearch
    int srcCurOffset = seaEndOffset;        // Current offset of *pSrc
    int seaCurOffset = seaEndOffset;        // Current offset of *pSearch

    int srcStartIndex 	= -1; // The start match index of each searching
    int step;                 // The steps need to forward search string

    while (srcCurOffset <= srcEndOffset) {
        srcStartIndex = srcCurOffset;

        displaycurstate(pSrc, pSearch, srcCurOffset);

        while (seaCurOffset > -1) {
            // Match current character
            if (pSearch[seaCurOffset] == pSrc[srcCurOffset]) {
                if (seaCurOffset == 0)
                    return srcCurOffset;

                --srcCurOffset; // Backward *pSrc current offset
                --seaCurOffset; // Backward *pSearch current offset
            } else {
                // Generate the steps need to forward
                step = badcharrule(pSearch, pSrc[srcCurOffset], seaCurOffset);

                srcCurOffset = srcStartIndex + step; // Forward
                seaCurOffset = seaEndOffset; // Reset the current offset of *pSearch

                break;
            }
        }
    }

    return -1;
}
