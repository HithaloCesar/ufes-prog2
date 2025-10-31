#ifndef USUARIO_H
#define USUARIO_H

/**
 * @struct tUsuario
 * @brief Estrutura que representa um usuário do sistema bancário.
 */
typedef struct Usuario {
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
} tUsuario;

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15]);

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user);

#endif
