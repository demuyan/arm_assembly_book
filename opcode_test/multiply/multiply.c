#include <stdio.h>
#include <stdint.h>

static inline __attribute__((always_inline))
uint32_t arm_mul(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("MUL %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mla(uint32_t v, uint32_t rs,uint32_t rn) {
  uint32_t d;
  asm ("MLA %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_mls(uint32_t v, uint32_t rs,uint32_t rn) {
  uint32_t d;
  asm ("MLS %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
void arm_umull(uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("UMULL %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_umlal(uint32_t v2, uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v2,rdhi=0;
  asm ("UMLAL %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_umaal(uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("UMAAL %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_smull(uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMULL %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_smlal(uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLAL %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
uint32_t arm_smulxy(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMULBT %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smulwy(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMULWT %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlaxy(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMLABT %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlawy(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMLAWT %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
void arm_smlalxy(uint32_t v, uint32_t rs,uint32_t rn, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLALBT %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
uint32_t arm_smuad(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMUAD %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smuad_x(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMUADX %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlad(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMLAD %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlad_x(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMLADX %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
void arm_smlald(uint32_t v, uint32_t rs,int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLALD %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_smlald_x(uint32_t v, uint32_t rs, int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLALDX %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
uint32_t arm_smusd(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMUSD %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smusd_x(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMUSDX %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlsd(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMLSD %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs), [Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
uint32_t arm_smlsd_x(uint32_t v, uint32_t rs, uint32_t rn) {
  uint32_t d;
  asm ("SMlSDX %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  return d;
}

static inline __attribute__((always_inline))
void arm_smlsld(uint32_t v, uint32_t rs,int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLSLD %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
void arm_smlsld_x(uint32_t v, uint32_t rs,int32_t* ary) {
  uint32_t rdlo=v,rdhi=0;
  asm ("SMLSLDX %[Rdlo], %[Rdhi], %[Rm], %[Rs]" 
       : [Rdlo] "+r" (rdlo),[Rdhi] "+r" (rdhi) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  ary[0] = rdhi;
  ary[1] = rdlo;
}

static inline __attribute__((always_inline))
uint32_t arm_smmul(uint32_t v, uint32_t rs) {
  uint32_t d;
  asm ("SMMUL %[Rd], %[Rm], %[Rs]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs));
  return d;
}

uint32_t arm_smmla(uint32_t v, uint32_t rs,uint32_t rn) {
  uint32_t d;
  asm ("SMMLA %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  return d;
}

uint32_t arm_smmls(uint32_t v, uint32_t rs,uint32_t rn) {
  uint32_t d;
  asm ("SMMLS %[Rd], %[Rm], %[Rs], %[Rn]" 
       : [Rd] "=r" (d) 
       : [Rm] "r" (v), [Rs] "r" (rs),[Rn] "r" (rn));
  return d;
}

int main() {
  uint32_t val,val2,val3;

  val = 0x0000005;
  val2 = 0x10;
  val3 = 0x4;
  printf("val = 0x%08X\n", val);
  printf("arm_mul(val, 0x%X) = 0x%08X\n", val2, arm_mul(val, val2));
  printf("arm_mla(val, 0x%X,0x%X) = 0x%08X\n", val2,val3, arm_mla(val, val2,val3));
  printf("arm_mls(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_mls(val, val2,val3));

  uint32_t ary[2];
  arm_umull(val, val2,ary);
  printf("arm_umull(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);
  arm_umlal(val3, val, val2,ary);
  printf("arm_umlal(0x%X,val, 0x%X) = 0x%08X%08X\n", val3,val2,ary[0],ary[1]);
  arm_umaal(val, val2,ary);
  printf("arm_umaal(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);
  arm_smull(val, val2,ary);
  printf("arm_smull(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);
  arm_smlal(val, val2,ary);
  printf("arm_smlal(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);

  printf("arm_smulxy(val, 0x%X) = 0x%08X\n", val2, arm_smulxy(val, val2));
  printf("arm_smulwy(val, 0x%X) = 0x%08X\n", val2, arm_smulwy(val, val2));
  printf("arm_smlaxy(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlaxy(val, val2,val3));
  printf("arm_smlawy(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlawy(val, val2,val3));

  arm_smlalxy(val, val2,val3,ary);
  printf("arm_smlalxy(val, 0x%X,0x%X) = 0x%08X%08X\n", val2,val3,ary[0],ary[1]);

  printf("arm_smuad(val, 0x%X) = 0x%08X\n", val2,arm_smuad(val, val2));
  printf("arm_smuad_x(val, 0x%X) = 0x%08X\n", val2,arm_smuad_x(val, val2));
  printf("arm_smlad(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlad(val, val2,val3));
  printf("arm_smlad_x(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlad_x(val, val2,val3));
  printf("arm_smusd(val, 0x%X) = 0x%08X\n", val2,arm_smusd(val, val2));
  printf("arm_smusd_x(val, 0x%X) = 0x%08X\n", val2,arm_smusd_x(val, val2));
  printf("arm_smlsd(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlsd(val, val2,val3));
  printf("arm_smlsd_x(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smlsd_x(val, val2,val3));

  arm_smlsld(val, val2,ary);
  printf("arm_smlsd(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);
  arm_smlsld_x(val, val2,ary);
  printf("arm_smlsd_x(val, 0x%X) = 0x%08X%08X\n", val2,ary[0],ary[1]);

  printf("arm_smmul(val, 0x%X) = 0x%08X\n", val2,arm_smmul(val, val2));
  printf("arm_smmla(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smmla(val, val2,val3));
  printf("arm_smmls(val, 0x%X,0x%X) = 0x%08X\n", val2,val3,arm_smmls(val, val2,val3));


  return 0;
}
