/*
    pf-init — simple and stupid init system
    Copyright © 2014 Oleksandr Natalenko aka post-factum <oleksandr@natalenko.name>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Credits:
    Rich Felker, http://ewontfix.com/14/
*/

#define _XOPEN_SOURCE 700
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	sigset_t set;
	int status;

	if (getpid() != 1)
		return 1;

	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, 0);

	if (fork())
		for (;;)
			wait(&status);

	sigprocmask(SIG_UNBLOCK, &set, 0);

	setsid();
	setpgid(0, 0);
	return execve("/etc/rc",
			(char *[])
			{
				"rc", 0
			},
			(char *[])
			{
				0
			});
}

