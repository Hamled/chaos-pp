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
# ifndef CHAOS_PREPROCESSOR_CONFIG_H
# define CHAOS_PREPROCESSOR_CONFIG_H
#
# /* CHAOS_PP_VARIADICS */
#
# if !defined CHAOS_PP_VARIADICS
#    if !__cplusplus && __STDC_VERSION__ >= 199901L
#        define CHAOS_PP_VARIADICS 1
#    else
#        define CHAOS_PP_VARIADICS 0
#    endif
# elif !CHAOS_PP_VARIADICS + 1 < 2
#    undef CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADICS 1
# else
#    undef CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADICS 0
# endif
#
# /* CHAOS_PP_NO_PREFIX */
#
# if CHAOS_PP_VARIADICS
#    if !defined CHAOS_PP_NO_PREFIX
#        define CHAOS_PP_NO_PREFIX 0
#    elif !CHAOS_PP_NO_PREFIX + 1 < 2
#        undef CHAOS_PP_NO_PREFIX
#        define CHAOS_PP_NO_PREFIX 1
#    else
#        undef CHAOS_PP_NO_PREFIX
#        define CHAOS_PP_NO_PREFIX 0
#    endif
# else
#    undef CHAOS_PP_NO_PREFIX
#    define CHAOS_PP_NO_PREFIX 0
# endif
#
# endif
