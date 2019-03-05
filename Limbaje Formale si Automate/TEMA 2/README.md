Cerinta:

Fiind dat un limbaj independent de context si un cuvant sa se verifice daca cunvatul apartine limbajului.


Implementare:

Creez un arbore de derivare unde fiecare nod contine cuvantul in care un nonterminal al cuvantului nodului tata a fost inlocuit cu o productie a nonterminalului. Cand cuvantul dintr-un nod devine mai mare decat cuvantul ce trebuie verificat, nodul nu mai este dezvoltat. Cand niciun nod temrinal nu mai este dezvolat si cuvantul nu a fost acceptat atunci cuvantul nu apartine limbajului.
