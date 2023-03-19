#include "stackheader.h"

// Fungsi untuk membuat stack
void createStack(stack &L) {
  top(L) = null;
  tail(L) = null;
}

// Fungsi untuk mengembalikan address yang telah diisi dengan char X
adr createItem(char X){
    adr P = new elm;
    info(P).ekspresi = X;
    next(P) = null;
    return P;
}

// Untuk menambah address P ke dalam stack
void pushStack(stack &L, adr P) {
  if (top(L) == null) {
    top(L) = P;
    tail(L) = P;
  } else {
    next(P) = top(L);
    top(L) = P;
  }
}

// Untuk menghapus atau pop data dari stack
void popStack(stack &L) {
  if (top(L) == null) {
    cout << "Stack Kosong" << endl;
  } else if (top(L) == tail(L)) {
    top(L) = null;
    tail(L) = null;
  } else {
    top(L) = next(top(L));
  }
}

// Fungsi untuk melakukan pengecekan apakah stack kosong
bool emptyStack(stack &L) {
  return top(L) == null;
}

// Untuk mendapatkan ukuran dari stack
int getSize(stack L) {
  int size = 0;
  adr P = top(L);
  while (P != null) {
    P = next(P);
    ++size;
  }
  return size;
}

// Fungsi untuk mengembalikan address teratas dari stack
adr getTop(stack L) {
  return top(L);
}
