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
# ifndef CHAOS_PREPROCESSOR_LIMITS_H
# define CHAOS_PREPROCESSOR_LIMITS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_LIMIT_AS_ARGS */
#
# define CHAOS_PP_LIMIT_AS_ARGS 5
# define CHAOS_PP_LIMIT_AS_ARGS_ID() CHAOS_PP_LIMIT_AS_ARGS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_AS_ARGS_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_AS_ARGS_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_AUTO_CAT */
#
# define CHAOS_PP_LIMIT_AUTO_CAT 16
# define CHAOS_PP_LIMIT_AUTO_CAT_ID() CHAOS_PP_LIMIT_AUTO_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_AUTO_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_AUTO_CAT_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_BIND */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_BIND 16
#    define CHAOS_PP_LIMIT_BIND_ID() CHAOS_PP_LIMIT_BIND
#    define CHAOS_PP_LIMIT_BIND_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_BIND_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_EQUALIZE */
#
# define CHAOS_PP_LIMIT_EQUALIZE 25
# define CHAOS_PP_LIMIT_EQUALIZE_ID() CHAOS_PP_LIMIT_EQUALIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_EQUALIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_EQUALIZE_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_EXPR */
#
# define CHAOS_PP_LIMIT_EXPR 512
# define CHAOS_PP_LIMIT_EXPR_ID() CHAOS_PP_LIMIT_EXPR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_EXPR_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_EXPR_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_HIGHPREC */
#
# define CHAOS_PP_LIMIT_HIGHPREC 10
# define CHAOS_PP_LIMIT_HIGHPREC_ID() CHAOS_PP_LIMIT_HIGHPREC
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_HIGHPREC_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_HIGHPREC_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_ITERATION */
#
# define CHAOS_PP_LIMIT_ITERATION 512
# define CHAOS_PP_LIMIT_ITERATION_ID() CHAOS_PP_LIMIT_ITERATION
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_ITERATION_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_ITERATION_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_ITERATION_DEPTH */
#
# define CHAOS_PP_LIMIT_ITERATION_DEPTH 5
# define CHAOS_PP_LIMIT_ITERATION_DEPTH_ID() CHAOS_PP_LIMIT_ITERATION_DEPTH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_ITERATION_DEPTH_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_ITERATION_DEPTH_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_LAMBDA */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_LAMBDA 50
#    define CHAOS_PP_LIMIT_LAMBDA_ID() CHAOS_PP_LIMIT_LAMBDA
#    define CHAOS_PP_LIMIT_LAMBDA_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_LAMBDA_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_MAG */
#
# define CHAOS_PP_LIMIT_MAG 512
# define CHAOS_PP_LIMIT_MAG_ID() CHAOS_PP_LIMIT_MAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_MAG_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_MAG_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_PLACEHOLDERS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_PLACEHOLDERS 25
#    define CHAOS_PP_LIMIT_PLACEHOLDERS_ID() CHAOS_PP_LIMIT_PLACEHOLDERS
#    define CHAOS_PP_LIMIT_PLACEHOLDERS_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_PLACEHOLDERS_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_SLOT */
#
# define CHAOS_PP_LIMIT_SLOT 5
# define CHAOS_PP_LIMIT_SLOT_ID() CHAOS_PP_LIMIT_SLOT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_SLOT_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_SLOT_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_SLOT_VALUE */
#
# define CHAOS_PP_LIMIT_SLOT_VALUE 10
# define CHAOS_PP_LIMIT_SLOT_VALUE_ID() CHAOS_PP_LIMIT_SLOT_VALUE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_SLOT_VALUE_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_SLOT_VALUE_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_TUPLE */
#
# define CHAOS_PP_LIMIT_TUPLE 25
# define CHAOS_PP_LIMIT_TUPLE_ID() CHAOS_PP_LIMIT_TUPLE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_TUPLE_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_TUPLE_ID)()
# endif
#
# /* CHAOS_PP_LIMIT_VARIADIC_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIMIT_VARIADIC_CAT 25
#    define CHAOS_PP_LIMIT_VARIADIC_CAT_ID() CHAOS_PP_LIMIT_VARIADIC_CAT
#    define CHAOS_PP_LIMIT_VARIADIC_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_LIMIT_VARIADIC_CAT_ID)()
# endif
#
# endif
