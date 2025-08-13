#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para sleep()

char username[50];
char password[50];
char confirmar_password[50];
char email[100];
int cargo;
int idade;

void codigo_confirmacao_admin()
{
    char cod_confirmacao_correto[] = "Teste1911#_";
    char cod_inserido[50];

    printf("------- Confirmacao -------\n");
    printf("Codigo de Confirmacao: ");
    scanf("%49s", cod_inserido);

    if (strcmp(cod_inserido, cod_confirmacao_correto) == 0)
    {
        printf("Codigo correto! Acesso concedido.\n");
    }
    else
    {
        printf("Codigo incorreto! Acesso negado.\n");
        exit(0); // Fecha o programa
    }
    printf("---------------------------\n");
}

void Login()
{
    printf("======= Login =======\n");
    printf("Username: ");
    scanf("%49s", username);
    printf("Password: ");
    scanf("%49s", password);
    printf("====================\n");

    // Só para teste
    printf("Username inserido: %s\n", username);
    printf("Password inserida: %s\n", password);
}

void Create_Account()
{
    printf("======= Criar Conta =======\n");
    printf("Nome: ");
    scanf("%49s", username);
    printf("Email: ");
    scanf("%99s", email);
    printf("Idade: ");
    scanf("%d", &idade);
    printf("Cargo (1 - Admin, 2 - User): ");
    scanf("%d", &cargo);

    switch (cargo)
    {
    case 1:
        printf("Cargo selecionado: Admin\n");
        codigo_confirmacao_admin();
        break;
    case 2:
        printf("Cargo selecionado: User\n");
        break;
    default:
        printf("Opcao Invalida, tente novamente!\n");
        return; // Sai da função
    }

    do
    {
        printf("Password: ");
        scanf("%49s", password);
        printf("Confirmar Password: ");
        scanf("%49s", confirmar_password);

        if (strcmp(password, confirmar_password) != 0)
        {
            printf("As passwords nao sao iguais... tente novamente!\n");
        }
    } while (strcmp(password, confirmar_password) != 0);

    printf("Conta criada com sucesso!\n");
    printf("Aguarde ...\n");
    sleep(2);
    Login();
}

int main()
{
    int opcao;
    printf("===== Menu =====\n");
    printf("1 - Login\n");
    printf("2 - Criar Conta\n");
    printf("=================\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        Login();
    }
    else if (opcao == 2)
    {
        Create_Account();
    }
    else
    {
        printf("Opção inválida.\n");
    }

    return 0;
}
