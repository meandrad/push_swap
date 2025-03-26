# -*- coding: utf-8 -*-
import os

def update_makefile(makefile_path, srcs_dir):
    """Update the SRCS variable in the Makefile with all .c files in srcs_dir."""
    # Verifica se o diretório srcs existe
    if not os.path.isdir(srcs_dir):
        raise FileNotFoundError("O diretório '{}' não existe.".format(srcs_dir))

    # Encontra todos os arquivos .c no diretório srcs
    srcs = []
    for root, _, files in os.walk(srcs_dir):
        for file in files:
            if file.endswith(".c"):
                # Obtém o caminho relativo do arquivo .c
                relative_path = os.path.relpath(os.path.join(root, file), srcs_dir)
                srcs.append("srcs/{}".format(relative_path.replace(os.sep, '/')))

    # Verifica se encontrou arquivos .c
    if not srcs:
        raise FileNotFoundError("Nenhum arquivo .c encontrado no diretório '{}'.".format(srcs_dir))

    # Adiciona quebras de linha no estilo Makefile (\) para SRCS
    formatted_srcs = " \\\n\t".join(srcs)

    # Lê o conteúdo do Makefile
    if not os.path.isfile(makefile_path):
        raise FileNotFoundError("O arquivo Makefile '{}' não existe.".format(makefile_path))

    with open(makefile_path, 'r') as file:
        lines = file.readlines()

    # Atualiza a linha que contém SRCS =
    updated_lines = []
    for line in lines:
        if line.strip().startswith("SRCS ="):
            updated_lines.append("SRCS = \\\n\t{}\n".format(formatted_srcs))
        else:
            updated_lines.append(line)

    # Escreve o conteúdo atualizado de volta no Makefile
    with open(makefile_path, 'w') as file:
        file.writelines(updated_lines)

    print("Makefile atualizado com sucesso!")

def main():
    # Caminho para o Makefile
    makefile_path = "./Makefile"
    # Caminho para o diretório srcs
    srcs_dir = "./srcs"

    # Atualiza o Makefile
    update_makefile(makefile_path, srcs_dir)

if __name__ == "__main__":
    main()