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
# ifndef CHAOS_PREPROCESSOR_REPETITION_FOR_H
# define CHAOS_PREPROCESSOR_REPETITION_FOR_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR(pred, op, macro, ...) CHAOS_PP_FOR_S(CHAOS_PP_STATE(), pred, op, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_ID)()
# else
#    define CHAOS_PP_FOR(pred, op, macro, state) CHAOS_PP_FOR_S(CHAOS_PP_STATE(), pred, op, macro, state)
# endif
#
# define CHAOS_PP_FOR_ID() CHAOS_PP_FOR
#
# /* CHAOS_PP_FOR_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_S(s, pred, op, macro, ...) CHAOS_IP_FOR_I(s, pred, op, macro, (__VA_ARGS__))
#    define CHAOS_PP_FOR_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_S_ID)()
# else
#    define CHAOS_PP_FOR_S(s, pred, op, macro, state) CHAOS_IP_FOR_I(s, pred, op, macro, (state))
# endif
#
# define CHAOS_PP_FOR_S_ID() CHAOS_PP_FOR_S
#
# define CHAOS_IP_FOR_I(s, pred, op, macro, ps) \
    CHAOS_IP_FOR_II(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), macro, CHAOS_PP_CALL(macro), ps) \
    /**/
# define CHAOS_IP_FOR_INDIRECT() CHAOS_IP_FOR_II
# define CHAOS_IP_FOR_II(_, s, pred, _p, op, _o, macro, _m, ps) \
    CHAOS_PP_EXPR_IIF _(_p()(s, pred, CHAOS_PP_UNPACK ps))( \
        _m()(s, macro, CHAOS_PP_UNPACK ps) \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOR_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, op, _o, macro, _m, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
        )) \
    ) \
    /**/
#
# /* CHAOS_PP_FOR_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_PARAMETRIC(size, pred, op, macro, ...) CHAOS_PP_FOR_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FOR_PARAMETRIC(size, pred, op, macro, state) CHAOS_PP_FOR_PARAMETRIC_S(CHAOS_PP_STATE(), size, pred, op, macro, state)
# endif
#
# define CHAOS_PP_FOR_PARAMETRIC_ID() CHAOS_PP_FOR_PARAMETRIC
#
# /* CHAOS_PP_FOR_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_PARAMETRIC_S(s, size, pred, op, macro, ...) \
        CHAOS_IP_FOR_PARAMETRIC_A(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), pred, op, macro, (__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FOR_PARAMETRIC_S(s, size, pred, op, macro, state) \
        CHAOS_IP_FOR_PARAMETRIC_A(CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), pred, op, macro, (state)) \
        /**/
# endif
#
# define CHAOS_PP_FOR_PARAMETRIC_S_ID() CHAOS_PP_FOR_PARAMETRIC_S
#
# define CHAOS_IP_FOR_PARAMETRIC_A(s, buffer, pred, op, macro, ps) \
    CHAOS_IP_FOR_PARAMETRIC_B(s, s, buffer, buffer, pred, CHAOS_PP_CALL(pred), op, CHAOS_PP_CALL(op), macro, CHAOS_PP_CALL(macro), ps) \
    /**/
# define CHAOS_IP_FOR_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_PARAMETRIC_B
# define CHAOS_IP_FOR_PARAMETRIC_B(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buffer))(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR)))( \
        CHAOS_IP_FOR_PARAMETRIC_C, CHAOS_IP_FOR_PARAMETRIC_E \
    )(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    /**/
# define CHAOS_IP_FOR_PARAMETRIC_C(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_PP_IIF)(_p()(s, pred, CHAOS_PP_UNPACK ps))( \
        CHAOS_IP_FOR_PARAMETRIC_D, \
        CHAOS_PP_TUPLE_EAT(11) \
    )(CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, op, _o, macro, _m, ps)) \
    /**/
# define CHAOS_IP_FOR_PARAMETRIC_D(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    _m()(s, macro, CHAOS_PP_UNPACK ps) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_FOR_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, pred, _p, op, _o, macro, _m, (_o()(s, op, CHAOS_PP_UNPACK ps)) \
    )) \
    /**/
# define CHAOS_IP_FOR_PARAMETRIC_E(s, o, buffer, shelf, pred, _p, op, _o, macro, _m, ps) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_IP_FOR_PARAMETRIC_INDIRECT CHAOS_PP_OBSTRUCT()()( \
        CHAOS_PP_NEXT(o), o, CHAOS_PP_NEXT(shelf), shelf, pred, _p, op, _o, macro, _m, ps \
    )) \
    /**/
#
# endif
