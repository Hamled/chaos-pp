# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_APPLY_H
# define CHAOS_PREPROCESSOR_FACILITIES_APPLY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_APPLY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_APPLY(...) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_IS_VARIADIC(__VA_ARGS__))( \
            CHAOS_PP_TUPLE_REM(?) __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_APPLY_ CHAOS_PP_LAMBDA(CHAOS_PP_APPLY_ID)()
# else
#    define CHAOS_PP_APPLY(x) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_IS_UNARY(x))( \
            CHAOS_PP_TUPLE_REM(1) x \
        ) \
        /**/
# endif
#
# define CHAOS_PP_APPLY_ID() CHAOS_PP_APPLY
#
# endif
