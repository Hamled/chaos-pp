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
# ifndef CHAOS_PREPROCESSOR_REPETITION_REPEAT_SHIFTED_H
# define CHAOS_PREPROCESSOR_REPETITION_REPEAT_SHIFTED_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/repetition/delineate_shifted.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_REPEAT_SHIFTED */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED(count, macro, ...) CHAOS_PP_REPEAT_SHIFTED_S(CHAOS_PP_STATE(), count, macro, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED(count, macro, data) CHAOS_PP_REPEAT_SHIFTED_S(CHAOS_PP_STATE(), count, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_ID() CHAOS_PP_REPEAT_SHIFTED
#
# /* CHAOS_PP_REPEAT_SHIFTED_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED_S(s, count, macro, ...) CHAOS_PP_DELINEATE_SHIFTED_S(s, count, CHAOS_PP_EMPTY, macro, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_S_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED_S(s, count, macro, data) CHAOS_PP_DELINEATE_SHIFTED_S(s, count, CHAOS_PP_EMPTY, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_S_ID() CHAOS_PP_REPEAT_SHIFTED_S
#
# /* CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC(size, count, macro, ...) CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S(CHAOS_PP_STATE(), size, count, macro, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC(size, count, macro, data) CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S(CHAOS_PP_STATE(), size, count, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_ID() CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC
#
# /* CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S(s, size, count, macro, ...) CHAOS_PP_DELINEATE_SHIFTED_PARAMETRIC_S(s, size, count, CHAOS_PP_EMPTY, macro, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S(s, size, count, macro, data) CHAOS_PP_DELINEATE_SHIFTED_PARAMETRIC_S(s, size, count, CHAOS_PP_EMPTY, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S_ID() CHAOS_PP_REPEAT_SHIFTED_PARAMETRIC_S
#
# endif
