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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_SPLIT_H
# define CHAOS_PREPROCESSOR_FACILITIES_SPLIT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_SPLIT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SPLIT(i, ...) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SPLIT_, i)(__VA_ARGS__)
#    define CHAOS_PP_SPLIT_ CHAOS_PP_LAMBDA(CHAOS_PP_SPLIT_ID)()
#    define CHAOS_IP_SPLIT_0(a, ...) a
#    define CHAOS_IP_SPLIT_1(a, ...) __VA_ARGS__
# else
#    define CHAOS_PP_SPLIT(i, im) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SPLIT_, i)(im)
#    define CHAOS_IP_SPLIT_0(a, b) a
#    define CHAOS_IP_SPLIT_1(a, b) b
# endif
#
# define CHAOS_PP_SPLIT_ID() CHAOS_PP_SPLIT
#
# endif
