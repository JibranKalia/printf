/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:37:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/14 10:43:11 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:40:13 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/04/13 16:09:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libftprintf.h"
#include <locale.h>
#include <fcntl.h>
#include <stdio.h>

int 	errors = 0;
int		reterrors = 0;

void	test(char const *fmt, ...)
{
	char	*libc;
	char	*mine;
	char	*pfstr;
	char 	*ftstr;
	int 	pfret;
	int 	ftret;
	int		passed = 1;
	va_list ap;
	va_list	cpy;

	va_start(ap, fmt);
	va_copy(cpy, ap);
	pfret = vasprintf(&libc, fmt, ap);
	ftret = ft_vasprintf(&mine, fmt, cpy);
	if (ft_strcmp(libc, mine))
	{
		ft_printf("%{red}Failed Test:%{eoc}\n");
		printf("Format: [\"%s\"]\n", fmt);
		printf("Yours: [%s]\n", mine);
		printf("Libc : [%s]\n", libc);
		errors++;
		passed = 0;
	}
	if (pfret != ftret)
	{
		ft_printf("%{red}Failed Return Value%{eoc}\n");
		printf("Format: [\"%s\"]\n", fmt);
		printf("Yours returned: [%d]\n", ftret);
		printf("Libc returned : [%d]\n", pfret);
		reterrors++;
		passed = 0;
	}
	va_end(ap);
	if (passed)
		ft_printf("%{green}Passed%{eoc}\n");
	free(mine);
}

void	bonus(char const *expected, char const *fmt, ...)
{
	int 	ftret;
	int		exret;
	char	*mine;
	int		passed = 1;
	va_list ap;
	va_start(ap, fmt);
	exret = ft_strlen(expected);
	ftret = ft_vasprintf(&mine, fmt, ap);
	if (ft_strcmp(expected, mine))
	{
		ft_printf("%{red}Failed Test:%{eoc}\n");
		printf("Format  : [\"%s\"]\n", fmt);
		printf("Yours   : [%s]\n", mine);
		printf("Expected: [%s]\n", expected);
		printf("Your ret  	 : [%d]\n", ftret);
		printf("YExpected ret: [%d]\n", exret);
		errors++;
		passed = 0;
	}
	va_end(ap);
	if (passed)
		ft_printf("%{green}Passed%{eoc}\n");
	free(mine);
}

int		main(int argc, char **argv)
{
	int ret1;
	int ret2;
	(void)argc;
	(void)argv;
	setlocale(LC_ALL, "en_US.UTF-8");
	  //Colors Tests

	/**
	 ft_printf("%{yellow}Color Tests:%{eoc}\n");
	 ft_printf("%{yellow}Foreground:%{eoc}\n");
	 printf("Red: \n");
	 ft_printf("%{red}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Red: \n");
	 ft_printf("%{bred}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Green: \n");
	 ft_printf("%{green}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Green: \n");
	 ft_printf("%{bgreen}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Yellow: \n");
	 ft_printf("%{yellow}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Yellow: \n");
	 ft_printf("%{byellow}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Blue: \n");
	 ft_printf("%{blue}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold blue: \n");
	 ft_printf("%{bblue}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Purple: \n");
	 ft_printf("%{purple}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Purple: \n");
	 ft_printf("%{bpurple}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Cyan: \n");
	 ft_printf("%{cyan}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Cyan: \n");
	 ft_printf("%{bcyan}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Black: \n");
	 ft_printf("%{black}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Black: \n");
	 ft_printf("%{bblack}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("White: \n");
	 ft_printf("%{white}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold White: \n");
	 ft_printf("%{bwhite}Hello %s Number %d%{eoc}2\n", "World", 4);
	 ft_printf("%{yellow}Background:%{eoc}\n");
	 printf("Red: \n");
	 ft_printf("%{b_red}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Red: \n");
	 ft_printf("%{b_bred}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Green: \n");
	 ft_printf("%{b_green}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Gree: \n");
	 ft_printf("%{b_bgreen}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Yellow: \n");
	 ft_printf("%{b_yellow}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Yellow: \n");
	 ft_printf("%{b_byellow}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Blue: \n");
	 ft_printf("%{b_blue}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold blue: \n");
	 ft_printf("%{b_bblue}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Purple: \n");
	 ft_printf("%{b_purple}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Purple: \n");
	 ft_printf("%{b_bpurple}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Cyan: \n");
	 ft_printf("%{b_cyan}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Cyan: \n");
	 ft_printf("%{b_bcyan}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Black: \n");
	 ft_printf("%{b_black}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold Black: \n");
	 ft_printf("%{b_bblack}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("White: \n");
	 ft_printf("%{b_white}Hello %s Number %d%{eoc}2\n", "World", 4);
	 printf("Bold White: \n");
	 ft_printf("%{b_bwhite}Hello %s Number %d%{eoc}2\n", "World", 4);
	 ft_printf("%{yellow}Multiple Colors\%{eoc}\n");
	 ft_printf("%{b_red}%{green}Hello %s Number %d%{eoc}2\n", "World", 4);
	 ft_printf("%{b_bwhite}}No EOC{eocc}2\n");
	 ft_printf("%This should be same color as the one on top%{eoc}2\n");
	 printf("Should not work: \n");
	 ft_printf("%{b_bbwhite}Hello %s Number %d%{eoc}2\n", "World", 4);
	 ft_printf("%{b_bwhites}Hello %s Number %d%{eocc}2\n", "World", 4);
	 ft_printf("%{{b_bwhite}}Hello %s Number %d%{eocc}2\n", "World", 4);
	 **/
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  //%b Tests
	 ft_printf("%{yellow}Binary Tests:%{eoc}\n");
	 bonus("100000", "%+b", 32);
	 bonus("100000    ", "%-10b", 32);
	 bonus("    100000", "%+ 10b", 32);
	 bonus("0b100100", "%#1.5b", 36);
	 bonus("0", "%b", 0);
	 bonus("00000", "%.5b", 0);
	 bonus("", "%.b", 0);
	 bonus("", "%#.0b", 0);
	 bonus("0" ,"%#.1b", 0);
	 bonus("", "%0.0b", 0);
	 bonus("0b1000001", "%# 9b",65);
	 bonus(" 0b1000001", "%# 10b",65);
	 bonus("      0b10", "%#10b", 2);
	 bonus("0b00000010", "%#010b", 2);
	 bonus("1100010", "%b", 98);
	 bonus("0b100100", "%#1.5b", 36);
	 bonus("100101101011010000111", "%b", 1234567);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	 ft_printf("%{yellow}Some Tests:%{eoc}\n");
	 test("%#x", 0);
	 test("@moulitest: %#.o %#.0o", 0, 0);
	 test("@moulitest: %#.x %#.0x", 0, 0);
	 test("%#.x", 132);
	 test("%#.0x", 132);
	 test("%#x", 132);
	 test("%#.1x", 132);
	 test("%#.x", 0);
	 test("%#.0x", 0);
	 test("%#x", 0);
	 test("%#.1x", 0);
	 test("{% 010d}", 42);
	 test("{%+03d}", 0);
	 test("%0+5d", -42);
	 test("%05d", -42);
	 test("%0+5d", 42);
	 test("%#0+5x", 42);
	 test("%+D", 15);
	 test("");
	 test("\n");
	 test("%%");
	 test("%d", 42);
	 test("%d%d", 42, 41);
	 test("%d%d%d", 42, 43, 44);
	 test("%ld", 2147483647);
	 test("%lld", 9223372036854775807);
	 test("%x", 505);
	 test("%X", 505);
	 test("%p", &test);
	 test("%20.15d", 54321);
	 test("%-10d", 3);
	 test("% d", 3);
	 test("%+d", 3);
	 test("%010d", 1);
	 test("%hhd", 0);
	 test("%jd", 9223372036854775807);
	 test("%zd", 4294967295);
	 test("%");
	 test("%U", 4294967295);
	 test("%u", 4294967295);
	 test("%o", 40);
	 test("%%#08x", 42);
	 test("%x", 1000);
	 test("%#X", 1000);
	 test("%s", NULL);
	 test("%S", L"ݗݜशব");
	 test("%s%s", "test", "test");
	 test("%s%s%s", "test", "test", "test");
	 test("%C", 15000);
	 test("%03c\n", 0);
	 test("%25.*+5s", 5, "hello World");
	 test("%.s", "hello World");
	 test("Libc 1: {%zhd}", "4294967296");
	 test("Libc 2: {%jhd}", "9223372036854775807");
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  //%n Tests
	 ft_printf("%{yellow}Some bonus Tests:%{eoc}\n");
	 int *ptr;
	 int ala = 42;
	 ptr = &ala;
	 test("%010n", ptr);
	 int		i[10];
	 char	s[10] = "Hello";
	 char    *s1;
	 char    *s2;
	 test("%s %s %n", s, s, &i[0]);
	 test("Output = %d", i[0]);
	  //Wildcard Tests
	 test("{%3*d}", 0, 0);
	 test("{%-*d}", -5, 42);
	 test("{%*d}", -5, 42);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  //%p Tests
	 ft_printf("%{yellow}%%p Tests:%{eoc}\n");
	 test("{%5p}", 0);
	 test("%.5p", 0);
	 test("%9.2p", 1234);
	 test("%.0p, %.p", 0, 0);
	 test("{%05p}", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	 ft_printf("%{yellow}Various Tests:%{eoc}\n");
	  //%Z Tests
	 test("{%-15Z}", 123);
	  //%C Tests
	 test("Libc: %10.C", 0);
	  //z Tests
	 test("%zO, %zO", 0, 32767);
	 test("%zD, %zD", 0, USHRT_MAX);
	  //%% Tests
	 test("Libc: %.0%");
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  //%o Tests
	 ft_printf("%{yellow}%%o Tests:%{eoc}\n");
	 test("%O", LLONG_MAX);
	 test("Libc: @moulitest: %5.o %5.0o", 0, 0);
	 test("Libc: %-10.5o", 2500);
	 test("Libc: %-05o", 2500);
	 test("Libc: %-#6o", 2500);
	 test("Libc: %#6o", 2500);
	 test("Libc: %-5o", 2500);
	 test("Libc: %05o", 42);
	 test("Libc: %5o", 41);
	 test("@moulitest: %o %0o", 0, 0);
	 test("@moulitest: %#o %#0o", 0, 0);
	 test("@moulitest: %#.o %#.0o", 0, 0);
	 test("%.-14o", 0);
	 test("%+ 10O", 0);
	 test("%+ 10.0o", 0);
	 test("%+010.0O", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  // %u
	 ft_printf("%{yellow}%%u Tests:%{eoc}\n");
	 test("%.-14U", 0);
	 test("%+ 10u", 0);
	 test("%+ 10.0U", 0);
	 test("%+010.0u", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	   //%x Tests
	 ft_printf("%{yellow}%%x Tests:%{eoc}\n");
	 test("%x", 0);
	 test("%#x", 0);
	 test("%03c", 1);
	 test("%#.0x", 0);
	 test("@moulitest: %#.x %#.0x", 0, 0);
	 test("@moulitest: %#.X %#.0X", 0, 0);
	 test("%#8X", 42);
	 test("%#8x", 42);
	 test("%#x", 42);
	 test("Libc: %#x", 55);
	 test("%.-14x", 0);
	 test("%+ 10X", 0);
	 test("%+ 10.0x", 0);
	 test("%+010.0X", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	   //%d Tests
	 ft_printf("%{yellow}%%d Tests:%{eoc}\n");
	 test("%.-14d", 0);
	 test("%+ 10d", 0);
	 test("%+ 10.0d", 0);
	 test("% d", 42);
	 test("{% 03d}", 0);
	 test("%hd", (short)65);
	 test("%-+10.5d", -4242);
	 test("%+10.5d", 4242);
	 test("%03.2d", 0);
	 test("%03.2d", 1);
	 test("% 24d", 50);
	 test("%05d", -42);
	 test("%05d", 42);
	 test("%4.15d", 42);
	 test("%4.15d", -42);
	 test("%0+5d", 42);
	 test("%+010.0d", 0);
	 test("%i", 142);
	 test("%10i", 142);
	 test("%1i", 142);
	 test("%010i", 142);
	 test("%-10i", 142);
	 test("%+d", 142);
	 test("%-d", 142);
	 test("%0d", 142);
	 test("%#d", 142);
	 test("% d", 142);
	 test("%10d", 142);
	 test("%1d", 142);
	 test("%2d", 142);
	 test("%3d", 142);
	 test("%50d", 142);
	 test("%+10d", 142);
	 test("%-10d", 142);
	 test("%010d", 142);
	 test("%#10d", 142);
	 test("% 10d", 142);
	 test("%+.5d", 142);
	 test("%-.5d", 142);
	 test("%0.5d", 142);
	 test("%#.5d", 142);
	 test("% .5d", 142);
	 test("%.0d", 142);
	 test("%.1d", 142);
	 test("%.2d", 142);
	 test("%.3d", 142);
	 test("%.25d", 142);
	 test("%1.0d", 142);
	 test("%2.1d", 142);
	 test("%3.2d", 142);
	 test("%5.3d", 142);
	 test("%10.25d", 142);
	 test("%.1d", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  // Wide Character Tests
	   setlocale(LC_CTYPE, "");
	  	wchar_t Char =  L'字';
	 ft_printf("%{yellow}Wide String Tests:%{eoc}\n");
	 test("Libc: [%lc]\n", L'字');
	 test("Mine: [fail%10lcpass]\n", '\0');
	 test("%lc\n", L'�');
	 test("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	 //  Null String Tests
	 ft_printf("%{yellow}Null String Tests:%{eoc}\n");
	 test("%s\n", 0);
	 test("%.0s\n", 0);
	 test("%.1s\n", 0);
	 test("%.2s\n", 0);
	 test("%.3s\n", 0);
	 test("%.4s\n", 0);
	 test("%.5s\n", 0);
	 test("%.6s\n", 0);
	 test("%.7s\n", 0);
	 test("%.17s\n", 0);
	 test("%.s\n", 0);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	   //Wide Character String Tests
	  	 setlocale(LC_CTYPE, "");
	 ft_printf("%{yellow}Wide String Tests:%{eoc}\n");
	 wchar_t *str =  L"💩💩💩";
	 wchar_t *thisstr = L"字Hello";
	 test("LIBC: {%ls}\n", thisstr);
	 test("%.7ls", str);
	 test("%.5ls", str);
	 test("%.6ls", str);
	 test("%.12ls", str);
	 test("%.52ls", str);
	 test("%10.5ls", str);
	 test("%-10.5ls", str);
	 test("%010.5ls", str);
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	//  Brandon Tests
	 char c = 'a';
	 test("%s", "Hello");
	 test("%s %s", "Hello", "World");
	 test("%.1s", "Hello");
	 test("%.*s", 2, "Hello");
	 test("%.*10s", 2, "Hello");
	 test("%-.*10s", 2, "Hello");
	 test("%0-.*10s", 2, "Hello");
	 test("%0.*10s", 2, "Hello");
	 test("%%");
	 test("%.%");
	 test("%10.%");
	 test("%-10.%");
	 test("%-10.r");
	 test("%-10.");
	 test("%-10.👩");
	 test("%p", &c);
	 test("%p", 0);
	 test("%.3p", &c);
	 test("%20.3p", &c);
	 test("%020.3p", &c);
	 test("%-020.3p", &c);
	 test("%s %p", "Hello", &c);
	 test("");
	 test("%d", 10);
	 test("%d", -10);
	 test("%hhd", 'j');
	 test("%hho", 'j');
	 test("%hhx", 'j');
	 test("%hhX", 'j');
	 test("%llX", (intmax_t)~0);
	 test("%jX", (intmax_t)~0);
	 test("%d", (int)~0);
	 test("%+ 10.0x", 0);
	 test("%+010.0x", 0);
	 test("%010.0x", 0);
	 test("%10.i", 0);
	 test("%010.0i", 0);
	 test("%0.100i", 0);
	 setlocale(LC_ALL, "");
	 test("%-10.👩");
	 test("%-10.👩d");
	 test("%ls", L"Hello");
	 test("%ls", L"👩🏽‍🚒");
	 test("%.3ls", L"👩🏽‍🚒");
	 test("%.5ls", L"👩🏽‍🚒");
	 test("% -010.5ls", L"👩🏽‍🚒");
	 test("% -010.5S", L"👩🏽‍🚒");
	 ft_printf("%{yellow}----------------------%{eoc}\n");
	  if (errors > 0 || reterrors > 0)
	  	ft_printf("%{bred}You failed on %d tests and %d rets%{eoc} 😡\n", errors , reterrors);
	  else
	  	ft_printf("%{bgreen}You passed everything%{eoc} 😀\n");
	  return (0);
	}
