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
# ifndef CHAOS_PREPROCESSOR_CONTROL_INCLUDE_IF_H
# define CHAOS_PREPROCESSOR_CONTROL_INCLUDE_IF_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/null.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_INCLUDE_IF */
#
# define CHAOS_PP_INCLUDE_IF(cond, file) CHAOS_PP_IF_SHADOW(cond)(file, CHAOS_PP_NULL())
# define CHAOS_PP_INCLUDE_IF_ID() CHAOS_PP_INCLUDE_IF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INCLUDE_IF_ CHAOS_PP_LAMBDA(CHAOS_PP_INCLUDE_IF)
# endif
#
# endif
