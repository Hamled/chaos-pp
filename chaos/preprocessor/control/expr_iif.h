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
# ifndef CHAOS_PREPROCESSOR_CONTROL_EXPR_IIF_H
# define CHAOS_PREPROCESSOR_CONTROL_EXPR_IIF_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_EXPR_IIF */
#
# define CHAOS_PP_EXPR_IIF(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_EXPR_IIF_, bit)
# define CHAOS_PP_EXPR_IIF_ID() CHAOS_PP_EXPR_IIF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPR_IIF_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPR_IIF)
#    define CHAOS_IP_EXPR_IIF_0(...)
#    define CHAOS_IP_EXPR_IIF_1(...) __VA_ARGS__
# else
#    define CHAOS_IP_EXPR_IIF_0(x)
#    define CHAOS_IP_EXPR_IIF_1(x) x
# endif
#
# endif
