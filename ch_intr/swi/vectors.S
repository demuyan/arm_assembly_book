              .text
              .code 32

              .global vectors_start
              .global vectors_end       
/////begin ch_intr_swi_asm
/*
 *  ベクターテーブル
 */ 
vectors_start:                                 
              LDR   PC, reset_handler_addr
              LDR   PC, undef_handler_addr
              LDR   PC, swi_handler_addr
              LDR   PC, prefetch_abort_handler_addr
              LDR   PC, data_abort_handler_addr
              B     .
              LDR   PC, irq_handler_addr       //-----(a-1)
              LDR   PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word halt
swi_handler_addr: .word swi_handler           //-----(a-2)
prefetch_abort_handler_addr: .word halt
data_abort_handler_addr: .word halt
irq_handler_addr: .word halt                   
fiq_handler_addr: .word halt                   
vectors_end:  

/* プログラム停止（無限ループ) */
halt:         b     .
/////end
/////begin ch_intr_swi_asm_2
/*
 * リセット処理
 * 最初はスーパーバイザモードで起動する
 */
reset_handler: 
/* スーパーバイザモード時のスタック領域の先頭アドレスをセットする */
              LDR   sp, =stack_top      //-----(1)
/* ベクターテーブルをセットする */
              MOV   r0, #0x00           //-----(2) ここから
              LDR   r1, =vectors_start  
              LDR   r3, =vectors_end
keep_loading: 
              LDR   r2, [r1, #0x0]
              STR   r2, [r0, #0x0]
              ADD   r0, r0, #0x4
              ADD   r1, r1, #0x4
              CMP   r1, r3
              BNE   keep_loading        //-----(2) ここまで

/* ユーザモードに切り替え */
              BIC   r1, r0, #0x1F       //-----(3) ここから
              ORR   r1, r1, #0x10
              MSR   cpsr, r1            //-----(4) ここまで
              LDR   sp, =user_stack_top  //-----(5) 
              
/* boot_main関数へ飛ぶ */
              BL    boot_main           //-----(6) 
              B     .
/////end
/*
 *  SWI発生時
 */               
              .global swi_handler
swi_handler:                             
              STMFD  sp!, {r0-r12,lr}
              LDR   r1,[lr, #-4]
              BIC   r1, r1, #0xff000000
              BL    c_swi_handler                                   
              LDMFD sp!, {r0-r12,pc}  
/*
 *  プロセッサモードを取得する
 */ 
              .global get_processor_mode
get_processor_mode:   
              mrs   r0,cpsr
              BIC   r0, r0, #0xffffffe0
              BX    lr

/*
 *  SWI命令を呼び出す
 */ 
              .global call_swi
call_swi:   
              PUSH {r0-r12,lr}
              SWI   0x120001
              POP  {r0-r12,lr}
              BX    lr

              .end
