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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/machine/add.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_MUL_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_MACHINE(x, y) CHAOS_PP_MUL_MACHINE_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_MUL_MACHINE_ID() CHAOS_PP_MUL_MACHINE
#    define CHAOS_PP_MUL_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_MACHINE)
# endif
#
# /* CHAOS_PP_MUL_MACHINE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_MACHINE_S(s, x, y) CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xMUL), x, y, 0xCHAOS(0xSTOP),)))
#    define CHAOS_PP_MUL_MACHINE_S_ID() CHAOS_PP_MUL_MACHINE_S
#    define CHAOS_PP_MUL_MACHINE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_MACHINE_S)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xMUL(s, p, x, y, k, ...) (, 0xCHAOS(0xMUL2), 0, x, y, k, p ## __VA_ARGS__)
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xMUL2(s, p, r, x, y, k, ...) \
        CHAOS_PP_IF(y)( \
            (, 0xCHAOS(0xADD), r, x, 0xCHAOS(0xMUL2), x, CHAOS_PP_DEC(y), k, p ## __VA_ARGS__), \
            (, k, r, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
