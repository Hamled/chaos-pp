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
# ifndef CHAOS_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
# define CHAOS_PREPROCESSOR_EXTENDED_PARTIAL_CAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_PARTIAL_CAT */
#
# define CHAOS_PP_PARTIAL_CAT(i, j) CHAOS_PP_CAT(CHAOS_IP_PARTIAL_CAT_, CHAOS_PP_PRIMITIVE_CAT(i, j))
# define CHAOS_PP_PARTIAL_CAT_ID() CHAOS_PP_PARTIAL_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARTIAL_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_PARTIAL_CAT)
# endif
#
# define CHAOS_IP_PARTIAL_CAT_00(a, b) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, b ## CHAOS_PP_PARTIAL)
# define CHAOS_IP_PARTIAL_CAT_01(a, b) CHAOS_PP_PRIMITIVE_CAT(CHAOS_PP_PARTIAL ## a, b)
# define CHAOS_IP_PARTIAL_CAT_10(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b ## CHAOS_PP_PARTIAL)
# define CHAOS_IP_PARTIAL_CAT_11(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b)
#
# define CHAOS_PP_PARTIALCHAOS_PP_PARTIAL
#
# define CHAOS_PP_PARTIAL_CAT_SHADOW(i, j) CHAOS_PP_CAT_SHADOW(CHAOS_IP_PARTIAL_CAT_SHADOW_, CHAOS_PP_PRIMITIVE_CAT_SHADOW(i, j))
#
# define CHAOS_IP_PARTIAL_CAT_SHADOW_00(a, b) CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_PP_PARTIAL ## a, b ## CHAOS_PP_PARTIAL)
# define CHAOS_IP_PARTIAL_CAT_SHADOW_01(a, b) CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_PP_PARTIAL ## a, b)
# define CHAOS_IP_PARTIAL_CAT_SHADOW_10(a, b) CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, b ## CHAOS_PP_PARTIAL)
# define CHAOS_IP_PARTIAL_CAT_SHADOW_11(a, b) CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, b)
#
# /* CHAOS_PP_PARTIAL */
#
# define CHAOS_PP_PARTIAL
# define CHAOS_PP_PARTIAL_ID() CHAOS_PP_PARTIAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARTIAL_ CHAOS_PP_LAMBDA(CHAOS_PP_PARTIAL_ID)()
# endif
#
# endif
