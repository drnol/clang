#ifndef CODEMIND_DBG

#define CODEMIND_DBG

#include <execinfo.h>

// CAUTION: this function works properly only with linux

#ifdef __unix__
#define printStackTrace() {                                    \
 void *buffer[200];                                            \
  char **strings;                                              \
  int nptrs = backtrace(buffer, 200);                          \
  printf("backtrace() returned %d addresses\n", nptrs);        \
  strings = backtrace_symbols(buffer, nptrs);                  \
  if (strings == NULL) {                                       \
      perror("backtrace_symbols");                             \
      exit(EXIT_FAILURE);                                      \
  }                                                            \
 for (int j = 0; j < nptrs; j++)                               \
      printf("%s\n", strings[j]);                              \
 free(strings);                                                \
}
#endif

#define printTokInfo(msg) {                                                                      \
    if(Tok.isAnyIdentifier()) {                                                                  \
    printf("%s : Tok[%s] = %s\n",msg,Tok.getName(),Tok.getIdentifierInfo()->getName().data());   \
  }                                                                                              \
  else {                                                                                         \
    printf("%s : Tok[%s]\n",msg,Tok.getName());                                                  \
  }                                                                                              \
}

#endif
