#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ✅ Necessário para strcmp()
#include <unistd.h> // ✅ Necessário para o Sleep()

char username[50];
char password[50];
char confirmar_password[50];
char email[100];
int cargo;
int idade;

void Login()
{
    printf("======= Login =======\n");
    printf("Username: ");
    scanf("%49s", username); // limitar a escrita de input a 49 + 1 caracteres
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
    printf("Aguarde ...");
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
