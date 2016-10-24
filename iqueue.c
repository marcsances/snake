/*
iqueue.c - C implementation of queue

Copyright (c) 2016, Marc Sances
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/ 

#include <stdlib.h>
#include <stdio.h>

typedef struct _qitem_s {
    void* data;
    void* next;
} _qitem;

void* qalloc(int dsize) {
    _qitem* qit = malloc(sizeof(_qitem));
    (*qit).data = NULL;
    (*qit).next = NULL;
}

void qpush(void* qptr, void* val) {
    _qitem* qit = (_qitem*)qptr;
    _qitem* nquit = malloc(sizeof(_qitem));
    _qitem* last;
    (*nquit).data = val;
    (*nquit).next = NULL;
    if ((*qit).data != NULL) {
        last = (*qit).data;
        (*last).next = nquit;
    }
    if ((*qit).next == NULL) {
        (*qit).next = nquit;
    }
    (*qit).data = nquit;
}

void* qpop(void* qptr) {
    _qitem* qit = (_qitem*)qptr;
    _qitem* popped;
    _qitem* next;
    if ((*qit).next != NULL) {
        popped = (*qit).next;
        (*qit).next = (*popped).next;
        return (*popped).data;
    } else return NULL;
}

void* qfront(void* qptr) {
    _qitem* qit = (_qitem*)qptr;
    _qitem* next;
    if ((*qit).next != NULL) {
        next = (*qit).next;
        return (*next).data;
    } else return NULL;
}

void* qback(void* qptr) {
    _qitem* qit = (_qitem*)qptr;
    _qitem* back;
    if ((*qit).data != NULL) {
        back = (*qit).data;
        return (*back).data;
    } else return NULL;
}

void qdestroy(void* qptr) {
    _qitem* qit = (_qitem*)qptr;
    _qitem* cur;
    void *nxt;
    if ((*qit).next!=NULL) {
        cur = (*qit).next;
        while ((*cur).next!=NULL) {
            nxt = (*cur).next;
            free(cur);
            cur = (_qitem*)nxt;
        }
    }
    free(qptr);
}

void pqueue(void* qptr) {
    fprintf(stderr,"dumping queue: ");
    _qitem* qit = (_qitem*)qptr;
    _qitem* cur;
    if ((*qit).next!=NULL) {
        cur = (*qit).next;
        fprintf(stderr,"%d,",*((int*)(*cur).data));
        while ((*cur).next!=NULL) {
            cur = (*cur).next;
            fprintf(stderr,"%d,",*((int*)(*cur).data));
        }
        fprintf(stderr,"\n");
    }
}