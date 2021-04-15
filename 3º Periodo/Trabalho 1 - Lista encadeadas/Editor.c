#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"

struct editor
{
    char *nome;
};

Editor *IniciaEditor(char *nome)
{   
    if(nome != NULL){
        Editor *editor = (Editor *)malloc(sizeof(Editor));
        editor->nome = strdup(nome);
        return editor;
    }
}

char *RetornaNomeEditor(Editor *editor)
{
    if(editor){
        return editor->nome;
    }
}

void ImprimeEditor(Editor *editor)
{   if(editor){
        printf("Nome editor: %s\n", editor->nome);
}
}

void DestroiEditor(Editor *editor)
{   
    if(editor){
        free(editor->nome);
        free(editor);
    }
}