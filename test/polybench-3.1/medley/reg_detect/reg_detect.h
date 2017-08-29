/**
 * reg_detect.h: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#ifndef REG_DETECT_H
# define REG_DETECT_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# if !defined(NITER) && !defined(LENGTH) && !defined(MAXGRID)
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define NITER 10
#   define LENGTH 32
#   define MAXGRID 2
#  endif

#  ifdef SMALL_DATASET
#   define NITER 100
#   define LENGTH 50
#   define MAXGRID 6
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define NITER 10000
#   define LENGTH 64
#   define MAXGRID 6
#  endif

#  ifdef LARGE_DATASET
#   define NITER 1000
#   define LENGTH 500
#   define MAXGRID 12
#  endif

#  ifdef EXTRALARGE_DATASET
#   define NITER 10000
#   define LENGTH 500
#   define MAXGRID 12
#  endif
# endif /* !N */


# ifndef DATA_TYPE
#  define DATA_TYPE __attribute__((annotate("no_float"))) float
# endif
#  define DATA_PRINTF_MODIFIER "%0.6lf "


#endif /* !REG_DETECT */