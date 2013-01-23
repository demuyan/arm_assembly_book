              .text
              .code 32
              
              .global vectors_start
              .global vectors_end
        
/* ベクターテーブル */
vectors_start: 
              LDR   PC, reset_handler_addr
              LDR   PC, undef_handler_addr
              LDR   PC, swi_handler_addr
              LDR   PC, prefetch_abort_handler_addr
              LDR   PC, data_abort_handler_addr
              B     .
              LDR   PC, irq_handler_addr
              LDR   PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word halt
swi_handler_addr: .word halt
prefetch_abort_handler_addr: .word halt
data_abort_handler_addr: .word halt
irq_handler_addr: .word irq_handler
fiq_handler_addr: .word 
vectors_end:  

halt:         b     .

/*
 * リセット処理
 * 最初はスーパーバイザーモードで起動する
 */
reset_handler: 

/* スタックポインタのアドレスをセットする */
              LDR   sp, =stack_top
/* ベクターテーブルをセットする */
              mov   r0, #0x00
              ldr   r1, =vectors_start
              ldr   r3, =vectors_end
keep_loading: 
              ldr   r2, [r1, #0x0]
              str   r2, [r0, #0x0]
              add   r0, r0, #0x4
              add   r1, r1, #0x4
              cmp   r1, r3
              bne   keep_loading

/* ステータスレジスタを取得 */
              MRS   r0, cpsr
/* IRQモードに切り替え */
              BIC   r1, r0, #0x1F
              ORR   r1, r1, #0x12
              MSR   cpsr, r1
/* IRQモードのスタックをセットする */
              LDR   sp, =irq_stack_top

/* スーパーバイザーモードに戻る */ 
              MSR   cpsr, r0
/* main関数へ飛ぶ */
              BL    main
              B     .

/*
 *  IRQ発生時
 */ 
              
              .global irq_handler
irq_handler:
              push  {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
              bl    irq_handler_func
              pop   {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
              subs  pc,lr,#4
              
/*
 *  IRQを許可する
 */ 
              .global enable_irq
enable_irq:   
              mrs   r0,cpsr
              bic   r0,r0,#0x80
              msr   cpsr_c,r0
              bx    lr
              
              .end