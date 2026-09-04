
# cub3D

*Este projeto foi criado como parte do currículo da 42 por jose-cad, kgagliar.*
## Descrição

**cub3D** é um projeto inspirado no clássico jogo Wolfenstein 3D, o primeiro FPS (First Person Shooter) da história. O objetivo é criar um motor gráfico de raycasting em 3D capaz de renderizar um labirinto a partir de uma perspectiva de primeira pessoa usando a biblioteca gráfica MiniLibX.

O projeto utiliza a técnica de raycasting para simular um ambiente 3D em tempo real, permitindo ao jogador navegar por um mapa definido em um arquivo de configuração. O desafio envolve implementar matemática vetorial, algoritmos de renderização, gerenciamento de texturas e input do usuário para criar uma experiência interativa fluida.

### Características Principais

**Versão Obrigatória:**
- Renderização 3D em tempo real usando raycasting
- Texturas diferenciadas para cada parede (Norte, Sul, Leste, Oeste)
- Cores personalizáveis para teto e chão
- Movimentação suave (W, A, S, D)
- Rotação da câmera (setas direcionais)
- Sistema de parsing robusto para arquivos `.cub`
- Validação completa de mapas

**Versão Bônus:**
- Sistema de portas interativas
- Sprites animados
- Minimapa em tempo real
- Controle de câmera com mouse
- Sistema de saída/objetivo
- Animações avançadas
- Detecção de colisão aprimorada

## Instruções

### Pré-requisitos

- Sistema operacional Linux ou macOS
- Biblioteca MiniLibX
- Compilador GCC
- Make

### Compilação

Para compilar a versão obrigatória:
```bash
make
```

Para compilar a versão com bônus:
```bash
make bonus
```

Para limpar os arquivos objeto:
```bash
make clean
```

Para limpar tudo (incluindo executáveis):
```bash
make fclean
```

Para recompilar do zero:
```bash
make re
```

### Execução

#### Versão Obrigatória
```bash
./cub3D mapas/mandatory.cub
```

#### Versão Bônus
```bash
./cub3D_bonus mapas/bonus.cub
```

### Formato do Arquivo de Mapa

O arquivo `.cub` deve conter:

**Texturas:**
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
```

**Cores (RGB):**
```
F 220,100,0    # Floor (chão)
C 225,30,0     # Ceiling (teto)
```

**Mapa:**
```
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Regras do Mapa:**
- `0` = espaço vazio
- `1` = parede
- `N/S/E/W` = posição inicial do jogador e orientação
- Apenas para bônus: `D` = porta, `X` = sprite, `E` = saída
- O mapa deve ser fechado por paredes

### Controles

**Versão Obrigatória:**
- `W` / `↑` - Mover para frente
- `S` / `↓` - Mover para trás
- `A` - Mover para esquerda
- `D` - Mover para direita
- `←` - Rotacionar câmera para esquerda
- `→` - Rotacionar câmera para direita
- `ESC` - Sair do jogo

**Controles Adicionais (Bônus):**
- `Mouse` - Rotação da câmera
- `E` - Interagir com portas
- `M` - Alternar minimapa

## Exemplos de Uso

### Testando Diferentes Mapas

```bash
# Mapa simples
./cub3D mapas/map.cub

# Mapa complexo com múltiplas salas
./cub3D mapas/complexo.cub

# Mapa com recursos bônus
./cub3D_bonus mapas/bonus.cub
```

### Testando Validação de Erros

```bash
# Arquivo inválido (deve retornar erro)
./cub3D mapas/invalido.cub
```
## Escolhas Técnicas

### Algoritmo de Raycasting

O projeto implementa o algoritmo DDA (Digital Differential Analyzer) para raycasting eficiente. Para cada coluna de pixels na tela:

1. **Inicialização do Raio:** Calcula a direção do raio baseado na posição da câmera
2. **DDA:** Avança o raio célula por célula no grid até atingir uma parede
3. **Cálculo de Distância:** Calcula a distância perpendicular para evitar efeito fisheye
4. **Projeção da Parede:** Determina a altura da parede na tela
5. **Texturização:** Mapeia a textura correta baseado no lado da parede atingido

### Gerenciamento de Memória

O projeto implementa um sistema robusto de limpeza de memória para evitar vazamentos:
- Liberação apropriada de texturas MLX
- Limpeza de arrays dinâmicos
- Tratamento de erros com cleanup automático

### Sistema de Colisão (Bônus)

Implementa verificação de colisão em 8 direções ao redor do jogador, permitindo movimento suave enquanto previne atravessar paredes.

## Recursos

### Video tutoriais
- https://www.youtube.com/@ManualdoC%C3%B3digo
- https://www.youtube.com/@programandoerrado.davidbuzatto
### Documentação Oficial

- [Documentação MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Tutorial de Raycasting - Lodev](https://lodev.org/cgtutor/raycasting.html)
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d)

### Artigos e Tutoriais

- [Raycasting Tutorial - permadi.com](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [Game Engine Black Book: Wolfenstein 3D](https://fabiensanglard.net/gebb/index.html)
- [Introdução à Computação Gráfica](https://www.scratchapixel.com/)

### Matemática e Algoritmos

- [Algoritmo DDA](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
- [Produto Vetorial e Rotações 2D](https://mathworld.wolfram.com/VectorProduct.html)
- [Field of View em Jogos 3D](https://en.wikipedia.org/wiki/Field_of_view_in_video_games)


**Aprendizado Conceitual:**
- Explicação de conceitos matemáticos (produto escalar, rotação vetorial)
- Clarificação do algoritmo DDA
- Compreensão de técnicas de texturização

## Autor

- jose-cad

## Licença

Este projeto faz parte do currículo educacional da 42 e está sujeito às suas políticas acadêmicas.

---

*Nota: Este projeto foi desenvolvido com fins educacionais como parte do programa da 42. O código original de Wolfenstein 3D é propriedade da id Software.*
