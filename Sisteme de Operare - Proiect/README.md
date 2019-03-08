#MutexPolicy

Scrieti un daemon in userland care sa decida politica de
acces la mutecsi creati cu ajutorul unui set nou de functii de sistem implementat de dumneavoastra:
mtxopen, mtxclose, mtxlock, mtxunlock, mtxlist si mtxgrant.
Ultimele doua functi sunt folosite de daemon pentru a stabili care proces obttine acces la mutex.
Mutecsii sunt vizibili de orice proces din sistem, dar fiecare proces paastreaza o lista de
mutecsi folositi (precum descriptorii de fisiere).
