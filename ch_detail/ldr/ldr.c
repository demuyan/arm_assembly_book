#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../wrap.h"

const char *display_flags(int x)
{
    static char b[256];
    b[0] = '\0';

    strcat(b, "n=");
    strcat(b, (x & 0x80)? "1":"0");
    strcat(b, " z=");
    strcat(b, (x & 0x40)? "1":"0");
    strcat(b, " c=");
    strcat(b, (x & 0x20)? "1":"0");
    strcat(b, " v=");
    strcat(b, (x & 0x10)? "1":"0");

    return b;
}

/*
 * LDR命令
 */
void arm_ldr_sample_1() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "MOV   r0,%[Rs1]     \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDR  r1,[r0,#4]     \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1)
    : [Rs1] "r" (rs1)
    : "r0","r1");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1);
}

/*
 * LDR命令
 */
void arm_ldr_sample_2() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "MOV   r0,%[Rs1]     \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDR  r1,[r0,#4]!     \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1)
    : [Rs1] "r" (rs1)
    : "r0","r1");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1);
}

/*
 * LDR命令
 */
void arm_ldr_sample_3() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "MOV   r0,%[Rs1]     \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDR  r1,[r0],#4     \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1)
    : [Rs1] "r" (rs1)
    : "r0","r1");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1);
}




/*
 * LDR命令
 */
void arm_ldria_sample_1() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "LDR   r2,=0         \n\t"
    "LDR   r3,=0         \n\t"
    "MOV   r0,%[Rs1]      \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDMIA  r0!,{r1-r3}  \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    "MOV  %[Rd2],r2      \n\t" 
    "MOV  %[Rd3],r3      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2), [Rd3] "=r" (rd3)
    : [Rs1] "r" (rs1)
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1); 
  printf("r2 = 0x%08X\n",rd2); 
  printf("r3 = 0x%08X\n",rd3); 

}
void arm_ldrib_sample_1() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "LDR   r2,=0         \n\t"
    "LDR   r3,=0         \n\t"
    "MOV   r0,%[Rs1]      \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDMIB  r0!,{r1-r3}  \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    "MOV  %[Rd2],r2      \n\t" 
    "MOV  %[Rd3],r3      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2), [Rd3] "=r" (rd3)
    : [Rs1] "r" (rs1)
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1); 
  printf("r2 = 0x%08X\n",rd2); 
  printf("r3 = 0x%08X\n",rd3); 

}

void arm_ldrda_sample_1() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "LDR   r2,=0         \n\t"
    "LDR   r3,=0         \n\t"
    "MOV   r0,%[Rs1]      \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDMDA  r0!,{r1-r3}  \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    "MOV  %[Rd2],r2      \n\t" 
    "MOV  %[Rd3],r3      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2), [Rd3] "=r" (rd3)
    : [Rs1] "r" (rs1)
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1); 
  printf("r2 = 0x%08X\n",rd2); 
  printf("r3 = 0x%08X\n",rd3); 

}

void arm_ldrdb_sample_1() {
  uint32_t rd0,rd00,rd1,rd2,rd3;
   
   uint32_t list[]=
     {
	0xcc,0xdd,0xee,0xff,0x12,0x34,0x56,0x78,
     };
   
   uint32_t* rs1 = &list[4];
   
  __asm__ (
    "LDR   r1,=0         \n\t"
    "LDR   r2,=0         \n\t"
    "LDR   r3,=0         \n\t"
    "MOV   r0,%[Rs1]      \n\t"
    "MOV   %[Rd00],r0    \n\t"
    "LDMDB  r0!,{r1-r3}  \n\t"
    "MOV  %[Rd0],r0      \n\t" 
    "MOV  %[Rd1],r1      \n\t" 
    "MOV  %[Rd2],r2      \n\t" 
    "MOV  %[Rd3],r3      \n\t" 
    : [Rd0] "=r" (rd0),[Rd00] "=r" (rd00), [Rd1] "=r" (rd1) ,[Rd2] "=r" (rd2), [Rd3] "=r" (rd3)
    : [Rs1] "r" (rs1)
    : "r0","r1","r2","r3");
  printf("r0 = 0x%08X\n",rd00); 
  printf("r0 = 0x%08X\n",rd0); 
  printf("r1 = 0x%08X\n",rd1); 
  printf("r2 = 0x%08X\n",rd2); 
  printf("r3 = 0x%08X\n",rd3); 

}

int main() {

  WRAP("ch_detail_ldr_1_a",arm_ldr_sample_1);
  WRAP("ch_detail_ldr_2_a",arm_ldr_sample_2);
  WRAP("ch_detail_ldr_3_a",arm_ldr_sample_3);

  WRAP("ch_detail_ldria_1_a",arm_ldria_sample_1);
  WRAP("ch_detail_ldrib_1_a",arm_ldrib_sample_1);
  WRAP("ch_detail_ldrda_1_a",arm_ldrda_sample_1);
  WRAP("ch_detail_ldrdb_1_a",arm_ldrdb_sample_1);

  return 0;
}
