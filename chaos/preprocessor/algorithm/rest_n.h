# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_REST_N_H
# define CHAOS_PREPROCESSOR_ALGORITHM_REST_N_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_REST_N */
#
# define CHAOS_PP_REST_N(n, g) CHAOS_PP_REST_N_BYPASS(CHAOS_PP_LIMIT_EXPR, n, g)
# define CHAOS_PP_REST_N_ID() CHAOS_PP_REST_N
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REST_N_ CHAOS_PP_LAMBDA(CHAOS_PP_REST_N_ID)()
# endif
#
# /* CHAOS_PP_REST_N_BYPASS */
#
# define CHAOS_PP_REST_N_BYPASS(s, n, g) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_REST_N_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), n, g)) \
    /**/
# define CHAOS_PP_REST_N_BYPASS_ID() CHAOS_PP_REST_N_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REST_N_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_REST_N_BYPASS_ID)()
# endif
#
# define CHAOS_IP_REST_N_INDIRECT() CHAOS_IP_REST_N_I
# define CHAOS_IP_REST_N_I(_, s, n, g) \
    CHAOS_PP_IF _(n)( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_REST_N_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_PP_REST _(g) \
        )), \
        g \
    ) \
    /**/
#
# endif
