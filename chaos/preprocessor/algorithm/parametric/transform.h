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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_TRANSFORM_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_TRANSFORM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_TRANSFORM_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TRANSFORM_PARAMETRIC(size, op, ...) CHAOS_PP_TRANSFORM_PARAMETRIC_S(CHAOS_PP_STATE(), size, op, __VA_ARGS__)
#    define CHAOS_PP_TRANSFORM_PARAMETRIC_ID() CHAOS_PP_TRANSFORM_PARAMETRIC
#    define CHAOS_PP_TRANSFORM_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_TRANSFORM_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_TRANSFORM_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TRANSFORM_PARAMETRIC_S(s, size, op, ...) \
        CHAOS_IP_TRANSFORM_PARAMETRIC_I(s, size, op, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))) \
        /**/
#    define CHAOS_PP_TRANSFORM_PARAMETRIC_S_ID() CHAOS_PP_TRANSFORM_PARAMETRIC_S
#    define CHAOS_PP_TRANSFORM_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_TRANSFORM_PARAMETRIC_S_ID)()
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_I(s, size, op, g, im) \
        CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_TRANSFORM_PARAMETRIC_A_INDIRECT, size, \
            op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), im \
        ) \
        /**/
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_A_INDIRECT() CHAOS_IP_TRANSFORM_PARAMETRIC_A
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_A(s, id, para, op, _o, type, g1, g2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g1))( \
            CHAOS_IP_TRANSFORM_PARAMETRIC_A_I, CHAOS_IP_TRANSFORM_PARAMETRIC_B \
        )(s, id, para, op, _o, type, g1, g2, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_A_I(s, id, para, op, _o, type, g1, g2, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(id)()( \
            s, CHAOS_IP_TRANSFORM_PARAMETRIC_A_INDIRECT, para, op, _o, type, CHAOS_PP_REST(g1), \
            CHAOS_PP_DEFER(CHAOS_PP_CONS)( \
                g2, \
                _o()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g1)) __VA_ARGS__) \
            ), __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_B_INDIRECT() CHAOS_IP_TRANSFORM_PARAMETRIC_B
#    define CHAOS_IP_TRANSFORM_PARAMETRIC_B(s, id, para, op, _o, type, g1, g2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g2))( \
            CHAOS_PP_EXPR_S(s) CHAOS_PP_OBSTRUCT(), \
            g1 CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_DEFER(id)()( \
            s, CHAOS_IP_TRANSFORM_PARAMETRIC_B_INDIRECT, para,,,, CHAOS_PP_CONS(g1, CHAOS_PP_FIRST(g2)), CHAOS_PP_REST(g2), \
        )) \
        /**/
# endif
#
# endif
