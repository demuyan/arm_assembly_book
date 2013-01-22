-*- mode: grep; default-directory: "/home/nrkz/github/arm_assembly_for_beginners/" -*-
Grep started at Thu Jan 17 13:56:51

find . -type f -print0 | "xargs" -0 -e lgrep -Au8 -Ia -n 'MSR'
./opcode_test/substract/substract.c:23:       "MSR cpsr_f,r1\n\t"
./opcode_test/add/add.c:19:    "MSR cpsr_f,r1\n\t"

Grep finished (matches found) at Thu Jan 17 13:56:51
