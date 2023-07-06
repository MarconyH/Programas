package Java;
import javax.swing.*;
import java.awt.*;

public class OlaMundo {
    public static void main(String[] args) {
        // Cria a janela
        JFrame janela = new JFrame("Cadastro");
        janela.setSize(800, 600);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Cria o painel principal e adiciona a janela
        JPanel painel = new JPanel();
        janela.add(painel);

        // Cria os elementos da interface
        JLabel rotulo_nome = new JLabel("Nome do Produto:");
        JTextField caixa_texto_nome = new JTextField(20);
        JLabel rotulo_cpf = new JLabel("Quantidade:");
        JTextField caixa_texto_cpf = new JTextField(11);

        // Adiciona os elementos ao painel
        painel.add(rotulo_nome);
        painel.add(caixa_texto_nome);
        painel.add(rotulo_cpf);
        painel.add(caixa_texto_cpf);

        // Exibe a janela
        janela.setVisible(true);
    }
}

