/**
 * jacobi-1d-imper.h: This file is part of the PolyBench 3.0 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#ifndef JACOBI_1D_IMPER_H
# define JACOBI_1D_IMPER_H

/* Default to STANDARD_DATASET. */
# if !defined(MINI_DATASET) && !defined(SMALL_DATASET) && !defined(LARGE_DATASET) && !defined(EXTRALARGE_DATASET)
#  define STANDARD_DATASET
# endif

/* Do not define anything if the user manually defines the size. */
# if !defined(TSTEPS) && ! defined(N)
/* Define the possible dataset sizes. */
#  ifdef MINI_DATASET
#   define TSTEPS 2
#   define N 500
#  endif

#  ifdef SMALL_DATASET
#   define TSTEPS 10
#   define N 1000
#  endif

#  ifdef STANDARD_DATASET /* Default if unspecified. */
#   define TSTEPS 100
#   define N 10000
#  endif

#  ifdef LARGE_DATASET
#   define TSTEPS 1000
#   define N 100000
#  endif

#  ifdef EXTRALARGE_DATASET
#   define TSTEPS 1000
#   define N 1000000
#  endif
# endif /* !N */


# ifndef DATA_TYPE
#  define DATA_TYPE __attribute__((annotate("no_float"))) float
# endif
#  define DATA_PRINTF_MODIFIER "%0.16lf "


#endif /* !JACOBI_1D_IMPER */
