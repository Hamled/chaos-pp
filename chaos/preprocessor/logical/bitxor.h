# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITXOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITXOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BITXOR */
#
# define CHAOS_PP_BITXOR(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITXOR_, x)
# define CHAOS_PP_BITXOR_ID() CHAOS_PP_BITXOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITXOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BITXOR)
# endif
#
# define CHAOS_IP_BITXOR_0(y) y
# define CHAOS_IP_BITXOR_1(y) CHAOS_PP_COMPL(y)
#
# if CHAOS_PP_NO_PREFIX
#    define BITXOR    CHAOS_PP_PREFIX(BITXOR)
#    define BITXOR_   CHAOS_PP_PREFIX(BITXOR_)
#    define BITXOR_ID CHAOS_PP_PREFIX(BITXOR_ID)
# endif
#
# endif
