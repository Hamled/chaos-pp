# /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_WSTRINGIZE_HPP
# define CHAOS_PREPROCESSOR_WSTRINGIZE_HPP
#
# include <chaos/preprocessor/cat.hpp>
# include <chaos/preprocessor/config.hpp>
# include <chaos/preprocessor/lambda/ops.hpp>
#
# /* CHAOS_PP_WSTRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WSTRINGIZE(...) CHAOS_PP_PRIMITIVE_WSTRINGIZE(__VA_ARGS__)
#    define CHAOS_PP_WSTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_WSTRINGIZE)
# else
#    define CHAOS_PP_WSTRINGIZE(x) CHAOS_PP_PRIMITIVE_WSTRINGIZE(x)
# endif
#
# define CHAOS_PP_WSTRINGIZE_ID() CHAOS_PP_WSTRINGIZE
#
# /* CHAOS_PP_PRIMITIVE_WSTRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE(...) CHAOS_PP_PRIMITIVE_CAT(L, #__VA_ARGS__)
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_WSTRINGIZE)
# else
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE(x) CHAOS_PP_PRIMITIVE_CAT(L, #x)
# endif
#
# endif
