#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int size_map = 32;
int ground = 500;
int shirina_ecrana = 352;
int visota_ecrana = 352;
int a, b, u, t; //�������� �� ���������� ������ ������� ���� ������������ �������(a - axis x, b - axis y),������ ������� �� � � ������. u, t ����� ���  ���������� �������� �����. �.�. � ������-����� ������������ ������ ������ ��������// 
int player;
float currentFrame = 0; //��� ����� ������//
float scroll_X = 0, scroll_Y = 0;
const int H = 12;
const int W = 150;
bool water;//������� � ����


String Map[H] = {
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                   0",
"0                     g                     0     H                                                            C                                       0",
"0         W                                                              m                      Q                                                      0",
"0                                                                     mm               fffffffffffffffffff                                                             0",
"0                                                                    mmm             O                                      R                         0",
"0              g    ddddd                     U                      mmmm                                                                            0",
"0    T                                 d0                           mmmmm                             N                                               0",
"0g                                    00              d0          mmmmmm            g                                                               0",
"BBBBBBBBBBBBBBBBBBBfBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBfffffffffffffBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKfffffffffffffKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",
"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK",

};

bool menu(RenderWindow& window)
{
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture;
    menuTexture1.loadFromFile("menu.png");
    menuTexture2.loadFromFile("menu.png");
    menuTexture3.loadFromFile("button.png");
    aboutTexture.loadFromFile("about.png");
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture3), about(aboutTexture);
    menu1.setTextureRect(IntRect(0, 0, 146, 219));
    menu2.setTextureRect(IntRect(149, 0, 158, 219));
    menu3.setTextureRect(IntRect(0, 0, 159, 80));
    menu4.setTextureRect(IntRect(160, 0, 159, 80));
    about.setTextureRect(IntRect(0, 0, 352, 352));
    bool isMenu = 1;
    int menuNum = 0;
    // ������� ������//
    menu1.setPosition(3, 10);// ���
    menu2.setPosition(200, 10);//�����
    menu3.setPosition(0, 270);// �����
    menu4.setPosition(200, 270);// � ���
    // ��������� ����. � ����� ���� ������������ ����� ������� ������ �� ���� ������, ����� �� ���� ��� ������ � ����������)//
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menu4.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(136, 0, 21));
        // ���� ������� �� ������ ������ ������ ����//
        if (IntRect(0, 10, 146, 219).contains(Mouse::getPosition(window))) { menu1.setColor(Color(109, 227, 248)); menuNum = 1; }
        if (IntRect(200, 10, 158, 219).contains(Mouse::getPosition(window))) { menu2.setColor(Color(109, 227, 248)); menuNum = 2; }
        if (IntRect(0, 270, 159, 80).contains(Mouse::getPosition(window))) { menu3.setColor(Color(109, 227, 248)); menuNum = 3; }
        if (IntRect(180, 270, 159, 80).contains(Mouse::getPosition(window))) { menu4.setColor(Color(109, 227, 248)); menuNum = 4; }
        //������� �� ������//
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) { player = 1; isMenu = false; } //����� ����//
            if (menuNum == 2) { player = 0; isMenu = false; }//����� ������//
            if (menuNum == 3) { window.close(); return false; isMenu = false; } //�������� ���� ��� ������� �� ������ "EXIT"//
            if (menuNum == 4) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); } //���������� ������ � ����������� � �������������//
        }
        //��������� ����//
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        // �������� ����//
        window.display();
    }
}

bool menu2(RenderWindow& window) {
    Texture menu_2_texture;
    menu_2_texture.loadFromFile("menu_2.png");
    Sprite menu_2_1(menu_2_texture), menu_2_2(menu_2_texture),menu_2_3(menu_2_texture);
    menu_2_1.setTextureRect(IntRect(1,52,150,34));
    menu_2_2.setTextureRect(IntRect(185,52,165,34));
    menu_2_3.setTextureRect(IntRect(0, 0, 350, 43));
    bool isMenu = 1;
    int menuNum = 0;
    // ������� ������//
    menu_2_1.setPosition(20, 100);
    menu_2_2.setPosition(170, 100); 
    menu_2_3.setPosition(10, 50);
    while (isMenu)
    {
        menu_2_1.setColor(Color::White);
        menu_2_2.setColor(Color::White);
        menuNum = 0;
        window.clear(Color::White);
        // ���� ������� �� ������ ������ ������ ����//
        if (IntRect(1, 100, 150, 34).contains(Mouse::getPosition(window))) { menu_2_1.setColor(Color(109, 227, 248)); menuNum = 1; }
        if (IntRect(200, 100, 165, 34).contains(Mouse::getPosition(window))) { menu_2_2.setColor(Color(109, 227, 248)); menuNum = 2; } 

        //������� �� ������//
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {isMenu = false;  return  true;}
            if (menuNum == 2) { menu(window); isMenu = false;  return false;}
        }
        //��������� ����//
        window.draw(menu_2_1);
        window.draw(menu_2_2);
        window.draw(menu_2_3);
        // �������� ����//
        window.display();
    }


}


class CHARACTER {
public:
    float dx, dy;
    FloatRect rect;
    bool onGround;
    Sprite sprite;
    float currentFrame;
    bool life = true;
    CHARACTER(Texture& image) {
        sprite.setTexture(image); //����� ������������� ������� �� ������-����� � ������������ � ��������� ������. 1- ��������� ������������ ����. 0 - ������������ ������//
        if (player == 1) {
            sprite.setTextureRect(IntRect(331, 223, 16, 27));
            sprite.setPosition(0, ground);
            rect = FloatRect(331, 223, 16, 27);
        }
        if (player == 0) {
            sprite.setTextureRect(IntRect(465, 300, 21, 27));
            sprite.setPosition(0, ground);
            rect = FloatRect(465, 300, 21, 27);
        }

        dx = dy = 0;
        currentFrame = 0;
    }
    void movement(float time) {
        rect.left += dx * time;
        Collision(0);
        if (!onGround) dy = dy + 0.0005 * time; // ���� ����� �� �� �����, �� ��������� ���������//
        rect.top += dy * time;
        onGround = false; 
        Collision(1);
        if (rect.top > ground) { rect.top = ground; dy = 0; onGround = true; } //���� ����� ��������� ���� ������ ground, ������� ������� ��� ����������� ��������������� �� ground//
        currentFrame += 0.005 * time;
        if (currentFrame > 6) currentFrame = -6;
        if (player == 1) {
            if (int(currentFrame) == 0) { a = 308 + u * 19; b = 19 * t; }
            if (dx != 0) { // � ����� ������-����� ���������� ����� ��������� ���� �������, ��-�� ����� ��� ��������� �������� � ����� ����� �������� �� ����� ������-����������� ���������� ������ � ����������� ���������. ��� �������� ���� ������ ���������� � ����������� ����������� � ����������� �� int(currentFrame)//
                if (dx > 0) { u = 0; t = 1; }
                if (dx < 0) { u = 1; t = -1; }
                if ((int(currentFrame) == 1) || (int(currentFrame) == -1)) { a = 331 + u * 19; b = 16 * t; }
                if ((int(currentFrame) == 2) || (int(currentFrame) == -2)) { a = 350 + u * 17; b = 15 * t; }
                if ((int(currentFrame) == 3) || (int(currentFrame) == -3)) { a = 370 + u * 17; b = 17 * t; }
                if ((int(currentFrame) == 4) || (int(currentFrame) == -4)) { a = 391 + u * 17; b = 17 * t; }
                if ((int(currentFrame) == 5) || (int(currentFrame) == -5)) { a = 415 + u * 18; b = 18 * t; }
                sprite.setTextureRect(IntRect(a, 223, b, 27));
            }
        }
        if (player == 0) {
            if (int(currentFrame) == 0) { a = 465 + u * 21; b = 21 * t; }
            if (dx != 0) {
                if (dx > 0) { u = 0; t = 1; }
                if (dx < 0) { u = 1; t = -1; }
                if ((int(currentFrame) == 1) || (int(currentFrame) == -1)) { a = 487 + u * 15; b = 15 * t; }
                if ((int(currentFrame) == 2) || (int(currentFrame) == -2)) { a = 503 + u * 15; b = 15 * t; }
                if ((int(currentFrame) == 3) || (int(currentFrame) == -3)) { a = 518 + u * 13; b = 13 * t; }
                if ((int(currentFrame) == 4) || (int(currentFrame) == -4)) { a = 535 + u * 13; b = 13 * t; }
                if ((int(currentFrame) == 5) || (int(currentFrame) == -5)) { a = 551 + u * 16; b = 16 * t; }
                sprite.setTextureRect(IntRect(a, 300, b, 27));

            }
        }

        sprite.setPosition(rect.left - scroll_X, rect.top - scroll_Y);
        dx = 0;
    }
    void Collision(int coll)
    {

        for (int i = rect.top / size_map; i < (rect.top + rect.height) / size_map; i++)
            for (int j = rect.left / size_map; j < (rect.left + rect.width) / size_map; j++)
            {
                if ((Map[i][j] == 'B') || (Map[i][j] == '0') || (Map[i][j] == 'g') || (Map[i][j] == 'd') || (Map[i][j] == 'p') || (Map[i][j] == 'm') || (Map[i][j] == 'K'))
                {
                    if (dy > 0 && coll == 1)
                    {
                        rect.top = i * size_map - rect.height;  dy = 0;   onGround = true;
                    }
                    if (dy < 0 && coll == 1)
                    {
                        rect.top = i * size_map + size_map;   dy = 0;
                    }
                    if (dx > 0 && coll == 0)
                    {
                        rect.left = j * size_map - rect.width;
                    }
                    if (dx < 0 && coll == 0)
                    {
                        rect.left = j * size_map + size_map;
                    }
                }
                if ((Map[i][j] == 'f') && (rect.top > i * size_map)) {
                    Clock clock1;
                    Time time1;
                    water = true;
                    while (time1.asMilliseconds() < 200) {
                        time1 = clock1.getElapsedTime(); 
                        if (time1.asMilliseconds() > 100) { life = false; }
                    }
                    clock1.restart();
                    
                 }
            }

    }
};

bool Startgame() {
    RenderWindow window(VideoMode(shirina_ecrana, visota_ecrana), "CHARACTER program");
    if (menu(window) == false) return false;
    Texture texture;
    texture.loadFromFile("111.png");

    CHARACTER character(texture);

    Clock clock;
    Texture background_texture_1 , background_texture_2;
    background_texture_1.loadFromFile("background_1.png");
    background_texture_2.loadFromFile("background_2.png");
    Sprite background_1(background_texture_1), background_2(background_texture_2);
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); // �������� �������� ����� ������ � �������� � ������� ����������. ��-�� ����� �������� ����� �� ������ ����������� ����� ����������//
        clock.restart();
        time = time / 500;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
                return false;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            character.dx = 0.1;
            character.movement(time);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            character.dx = -0.1;
            character.movement(time);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (character.onGround) { character.dy = -0.35; character.onGround = false; }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }
        character.movement(time);
        if (character.rect.left>shirina_ecrana/2) scroll_X = character.rect.left - shirina_ecrana/2;
        //if (character.rect.top>visota_ecrana/2) scroll_Y = character.rect.top - visota_ecrana/2;

        window.clear(Color(38,42,67));//(23,13,123));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W ; j++)
            {
                if (Map[i][j] == 'B') { background_1.setTextureRect(IntRect(269, 23, 32, 32));      background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1); }// ����� � ������
                if (Map[i][j] == '0') { background_1.setTextureRect(IntRect(339, 199, 32, 32));     background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1); }// ����� � �������
                if (Map[i][j] == 'g') { background_1.setTextureRect(IntRect(198, 304, 32, 32));     background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1);}// ���������� �����
                if (Map[i][j] == 'd') { background_1.setTextureRect(IntRect(375, 339, 32, 32));     background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1);}// �������� ������
                if (Map[i][j] == 'f') { background_1.setTextureRect(IntRect(233, 268, 32, 32));     background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1); }// ����
                if (Map[i][j] == 'p') { background_1.setTextureRect(IntRect(233, 58, 32, 32));      background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1);}// ����� � �������
                if (Map[i][j] == 'm') { background_1.setTextureRect(IntRect(92, 233, 32, 32));      background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1);}// �������
                if (Map[i][j] == 'K') { background_1.setTextureRect(IntRect(269, 128, 32, 32));     background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1); }// �����
                if (Map[i][j] == 'i') { background_1.setTextureRect(IntRect(93, 59, 32, 32));       background_1.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_1); }// �������� ������
                
                if (Map[i][j] == 'W') { background_2.setTextureRect(IntRect(476, 70, 70, 73));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2);}// ������� 1
                if (Map[i][j] == 'Q') { background_2.setTextureRect(IntRect(421, 242, 118, 53));    background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2);}// ������� 2
                if (Map[i][j] == 'R') { background_2.setTextureRect(IntRect(62, 161, 59, 58));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2);}// ������� 3
                if (Map[i][j] == 'T') { background_2.setTextureRect(IntRect(179, 71, 69, 71));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2); }// ������� 4
                if (Map[i][j] == 'U') { background_2.setTextureRect(IntRect(347, 72, 65, 69));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2);}// ������� 5
                if (Map[i][j] == 'H') { background_2.setTextureRect(IntRect(59, 238, 60, 58));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2); }// ������� 6
                if (Map[i][j] == 'O') { background_2.setTextureRect(IntRect(178, 73, 67, 68));      background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2); }// ������� 7
                if (Map[i][j] == 'N') { background_2.setTextureRect(IntRect(123, 241, 66, 51));     background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2); }// ������� 8
                if (Map[i][j] == 'C') { background_2.setTextureRect(IntRect(481, 152, 54, 51));     background_2.setPosition(j * size_map - scroll_X, i * size_map - scroll_Y);     window.draw(background_2); }// ������� 9
                if (Map[i][j] == ' ') continue;
           
            
            }
        }
        //if (water == true) character.sprite.setColor(Color::Red);
        if (character.life == false) { return menu2(window); }
        window.draw(character.sprite);
        window.display();

    }


}

void game_running() {
    if (Startgame()) { game_running(); }
}

int main() {
    game_running();
    return 0;
}