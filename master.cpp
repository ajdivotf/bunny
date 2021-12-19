#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

const int HEIGHT_MAP = 15;//размер карты высота
const int WIDTH_MAP = 150;//размер карты ширина 

//копии уровней для замены после проигрыща или выхода из игры
sf::String temp_up[HEIGHT_MAP] =
{
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                         cc                                       wh",
	"w                                                                         ccc                           gggg                                       wh",
	"w       c                                                                                 cc       c                              bbbb             wh",
	"w      gggg                                                                             gggggg gg  ggg                           bbbbb             wh",
	"w                  b                   b                             bbbbb   bbbbb                                              bbbbbb             wh",
	"w                  b                   b                            bbbbbb   bbbbbb                                            bbbbbbb             wh",
	"w         cc       b      s            b          ccccc      ss    bbbbbbbhhhbbbbbbb         cc            s        ccc       bbbbbbbb             wh",
	"ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggwwwggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggvvvvvvgg",
};

sf::String temp_down[HEIGHT_MAP] =
{
	"gwwwwwwgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
	"g                                                          bbb                                                                bbbbbb               gg",
	"g                                                                                                                                 bb               gg",
	"g                                                          ccc                                                                    bb               gg",
	"g                                                                                                                                 bb               gg",
	"g                           cccc                           bbb                                                                 c  bb               gg",
	"g                           bbbb                                                                                              bbbbbb               gg",
	"g                       b  cb  bc  b                                                               c c                                             gg",
	"g                       bbbbb  bbbbb                                                              ooooo                                            gg",
	"g                                                                                                                        bbb                       gg",
	"g                                                                                                                                                  gg",
	"gg                                                               b                   b                                                             gg",
	"ggg                                                           b  b                   b  b                                                          gg",
	"ggggggg          c                              c c        b  b  b                   b  b  b               ccc                                     gg",
	"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggvvvvvvgg",
};

//уровни
sf::String tile_map_up[HEIGHT_MAP] =
{
	"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                                                                  wh",
	"w                                                                                                         cc                                       wh",
	"w                                                                         ccc                           gggg                                       wh",
	"w       c                                                                                 cc       c                              bbbb             wh",
	"w      gggg                                                                             gggggg gg  ggg                           bbbbb             wh",
	"w                  b                   b                             bbbbb   bbbbb                                              bbbbbb             wh",
	"w                  b                   b                            bbbbbb   bbbbbb                                            bbbbbbb             wh",
	"w         cc       b      s            b          ccccc      ss    bbbbbbbhhhbbbbbbb         cc            s        ccc       bbbbbbbb             wh",
	"ggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggwwwggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggvvvvvvgg",
};

sf::String tile_map_down[HEIGHT_MAP] =
{
	"gwwwwwwgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
	"g                                                          bbb                                                                bbbbbb               gg",
	"g                                                                                                                                 bb               gg",
	"g                                                          ccc                                                                    bb               gg",
	"g                                                                                                                                 bb               gg",
	"g                           cccc                           bbb                                                                 c  bb               gg",
	"g                           bbbb                                                                                              bbbbbb               gg",
	"g                       b  cb  bc  b                                                               c c                                             gg",
	"g                       bbbbb  bbbbb                                                              ooooo                                            gg",
	"g                                                                                                                        bbb                       gg",
	"g                                                                                                                                                  gg",
	"gg                                                               b                   b                                                             gg",
	"ggg                                                           b  b                   b  b                                                          gg",
	"ggggggg          c                              c c        b  b  b                   b  b  b               ccc                                     gg",
	"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggvvvvvvgg",
};

//класс игрока
class Person
{
	protected:
		bool life, on_ground;//игрок жив, игрок на земле для прыжка и etc
		bool win;//игрок победил
		int health;//здоровье игрока
		double x, y;//координаты игрока
		double width, height;//ширина и высота картинки
		double ax, ay;//ускорение
		double speed;//скорость
		std::string file;//файл
		Texture texture;
		Sprite sprite;
	public:
		double start_x, start_y;
		Person(std::string f, double xex, double yex, double wid, double hei);
		~Person() {};
		bool update(float time);//отвечает за движение персонажа
		virtual bool collision(int dir);//столкновение с элементами карты
		int& get_health() { return health; };
		double& get_x() { return x; };
		double& get_y() { return y; };
		double& get_height() { return height; };
		double& get_width() { return width; };
		double& get_ax() { return ax; };
		double& get_ay() { return ay; };
		double& get_speed() { return speed; };
		bool& get_life() { return life; };
		bool& get_win() { return win; };
		bool& get_ground() { return on_ground; };
		Sprite& get_sprite() { return sprite; };
};


class Enemy : public Person//враг наследуется от игрока
{
public:
	Enemy(std::string f, double xex, double yex, double wid, double hei);
	~Enemy() {};
	void update_dog(float time);//для движения собаки
	void update_snake(float time);//для движения змеи
	bool collision(int dir = 0);//столкновение с картой
	bool crash(Person& player);//столкновение с игроком
};

//для плавности
sf::Time t1 = sf::microseconds(10000);
sf::Time t2 = sf::milliseconds(10);
sf::Time t3 = sf::seconds(0.01f);
float CurrentFrame = 0;
//количество условных морковок на данный момент и максимальное за сеанс
int count_carrots = 0, maximum = 0;
View view;//камера вида
int care = 0;//предупреждение при потере жизней
void view_object_cord(Person& object);//перемещение камеры вида
void restart(Person& object, Enemy& enemy);//рестарт при столкновении с врагом или падении в яму
//рестарт карты при переходе на другой уровень, проигрыше или выходе в меню
void restart_mark(Person& object, Enemy& enemy);
int lose = 0, adver = 0, go = 0;//метки проигрыша и возможности передвигаться
int gone = true;//ещё одна возможность двигаться
int mark = 1;//номер уровня
bool end = false;//кончилась ли игра
int c_win = 0;
bool mode = true;//в меню ли мы
bool move = false;//можно ли двигаться

int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "bunny");
	//карта
	Texture t_map;
	t_map.loadFromFile("map.png");
	Sprite map(t_map);
	Texture t_back, t_back1;
	t_back.loadFromFile("back.png");
	Sprite back(t_back);
	t_back1.loadFromFile("back1.png");
	Sprite back1(t_back1);
	back.setPosition(0, 0);
	//надписи
	Font font;
	font.loadFromFile("Teletactile.otf");
	Text carr("", font, 20);//морковки
	Text lives("", font, 20);//жизни
	Text ad("", font, 50);//предупреждения
	Text enter("", font, 20);
	enter.setString("ENTER");
	enter.setFillColor(Color::White);
	Text play("", font, 60);
	play.setString("PLAY");
	play.setFillColor(Color::White);
	Text best("", font, 30);
	std::string r_best = "BEST: ";
	best.setString("BEST: 0");
	best.setFillColor(Color::White);
	Text acc("", font, 60);
	acc.setFillColor(Color::White);
	acc.setPosition(155, 80);
	//технические моменты
	view.reset(sf::FloatRect(0, 0, 640, 480));
	Clock clock;
	float time = 0;
	//игрок и враги
	Person bunny("bunny.png", 54, 383, 40, 70);
	Enemy dog("dog.png", 1184, 416, 60, 50);
	Enemy snake("snake.png", 2300, 390, 60, 60);
	//музыка и звуки
	Music music;//при беге
	Music f_lose;//при проигрыше
	Music menu_after;//при выходе в меню
	SoundBuffer failBuffer;
	failBuffer.loadFromFile("fail.ogg");
	Sound fail(failBuffer);
	SoundBuffer winBuffer;
	winBuffer.loadFromFile("win.ogg");
	Sound winable(winBuffer);
	while (window.isOpen())//пока открыта программа
	{
		if (bunny.get_life())
			time = clock.getElapsedTime().asMicroseconds();//технические моменты
		else if (lose != 5000 and !mode)//движение камеры по карте при проигрыше
		{
			view.move(0.1, 0);//со скоростью 0.1
			lose++;
		}
		else if (mode) lose = 0;//если выходим в меню, то перестаем двигать камеру
		else if (lose >= 5000)//при окончании промотки камеры выходим в меню без нажатия клавиш
		{
			lose = 0; 
			mode = true;
		}
		//техническое
		view_object_cord(bunny);
		clock.restart();
		time = time / 300;
		//события
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			//выход из меню при нажатии "PLAY"
			if (event.type == Event::MouseButtonPressed and mode)
				if (event.key.code == Mouse::Left)
				{
					if (IntRect(240, 235, 180, 40).contains(Mouse::getPosition(window)))
					{
						mode = false;//вышли из меню
						count_carrots = 0;//обнулили счётчик морковок
						move = true;//можем двигаться
					}
				}
			//выход в меню при нажатии "ENTER"
			if (event.type == Event::MouseButtonPressed && move)
				if (event.key.code == Mouse::Left)
				{
					if (IntRect(22, 445, 74, 16).contains(Mouse::getPosition(window)))
					{
						mode = true;//мы в меню
						move = false;//не можем двигаться
						//перезапускаем всё
						restart_mark(bunny, dog);
						restart_mark(bunny, snake);
						mark = 1;//возвращаемся на первую карту, даже если хотим выйти во второй
						for (int i = 0; i < HEIGHT_MAP; i++)
						{
							tile_map_up[i] = temp_up[i];
							tile_map_down[i] = temp_down[i];
						}
					}
				}
		}
		//двжение
		if (Keyboard::isKeyPressed(Keyboard::Left) and move)//влево
		{
			if (bunny.get_life() and gone)
			{
				CurrentFrame += 0.001 * time;
				if (CurrentFrame > 5) CurrentFrame -= 5;//подобие анимации
				bunny.get_sprite().setTextureRect(IntRect(50 * int(CurrentFrame), 80, 50, 70));
				bunny.get_ax() = -0.17;//скорость персонажа
				view_object_cord(bunny);//камера следит за игроком
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) and move)//вправо
		{
			if (bunny.get_life() and gone)
			{
				CurrentFrame += 0.001 * time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				bunny.get_sprite().setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 70));
				bunny.get_ax() = 0.17;
				view_object_cord(bunny);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) and Keyboard::isKeyPressed(Keyboard::Up) and move)//вверх и вправо
		{
			if (bunny.get_life() and bunny.get_ground() and gone)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				bunny.get_sprite().setTextureRect(IntRect(50 * int(CurrentFrame), 230, 50, 223));
				bunny.get_ay() = -0.5;
				bunny.get_ground() = false;
				view_object_cord(bunny);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) and Keyboard::isKeyPressed(Keyboard::Up) and move)//вверх и влево
		{
			if (bunny.get_life() and bunny.get_ground() and gone)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				bunny.get_sprite().setTextureRect(IntRect(50 * int(CurrentFrame), 150, 50, 80));
				bunny.get_ay() = -0.5;
				bunny.get_ground() = false;
				view_object_cord(bunny);
			}
		}
		if (bunny.update(time))//для обновления координат, скорость и так далее
			fail.play();//if-условие вызывается при столкновении - в функции закручена коллизия
		if (mark == 1)//если мы столкнулись на первой карте
		{
			dog.update_dog(time);
			if (dog.crash(bunny) and bunny.get_life())
				fail.play();
		}
		else//а если на второй
		{
			snake.update_snake(time);
			if (snake.crash(bunny) and bunny.get_life())
				fail.play();
		}
		window.setView(view);
		if (mark == 1)//отрисовываем первую карту
		{
			window.clear(Color(87, 169, 240));
			window.draw(back);
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (tile_map_up[i][j] == 'g')//земля
						map.setTextureRect(IntRect(0, 0, 32, 32));
					else if (tile_map_up[i][j] == 'h')//пустое пространство для падения в яму
						map.setTextureRect(IntRect(32, 0, 32, 32));
					else if (tile_map_up[i][j] == 'c')//морковки
						map.setTextureRect(IntRect(64, 0, 32, 32));
					else if (tile_map_up[i][j] == 's')//вишни
						map.setTextureRect(IntRect(96, 0, 32, 32));
					else if (tile_map_up[i][j] == 'b')//куст
						map.setTextureRect(IntRect(128, 0, 32, 32));
					if (tile_map_up[i][j] != ' ' and tile_map_up[i][j] != 'w' and tile_map_up[i][j] != 'v')
					{//пустое пространство, границы и конец карты не отрисовываем
						map.setPosition(j * 32, i * 32);
						window.draw(map);
					}
				}
		}
		else
		{
			window.clear(Color::Black);
			window.draw(back1);
			if (bunny.get_win() and !end)
			{
				restart_mark(bunny, dog);
			}
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (tile_map_down[i][j] == 'g' or tile_map_down[i][j] == 'v')//земля или конец карты
						map.setTextureRect(IntRect(161, 0, 32, 32));
					else if (tile_map_down[i][j] == 'h')//ну видимо для красоты
						map.setTextureRect(IntRect(32, 0, 32, 32));
					else if (tile_map_down[i][j] == 'c')//кукуруза
						map.setTextureRect(IntRect(226, 0, 32, 32));
					else if (tile_map_down[i][j] == 'b')//кирпичи
						map.setTextureRect(IntRect(194, 0, 32, 32));
					else if (tile_map_down[i][j] == 'o')//исчезающие кирпичи
						map.setTextureRect(IntRect(194, 0, 32, 32));
					if (tile_map_down[i][j] != ' ' and tile_map_down[i][j] != 'w')
					{//пустое пространство и края карты не отрисовываем
						map.setPosition(j * 32, i * 32);
						window.draw(map);
					}
				}
		}
		//считаем морковки, жизни
		carr.setString(std::to_string(count_carrots));
		carr.setPosition(view.getCenter().x - 290, view.getCenter().y - 230);
		lives.setString("lives\n    " + std::to_string(bunny.get_health() / 20));
		lives.setPosition(view.getCenter().x + 200, view.getCenter().y - 230);
		window.draw(lives);
		window.draw(carr);
		//обычная музыка при беге
		if (music.getStatus() == Music::Stopped and bunny.get_life() and !mode)
		{
			music.openFromFile("race.ogg");
			music.play();
		}
		//если заяц умер, то она останавливается
		else if (!bunny.get_life())
			music.stop();
		//при выводе предупреждения
		if (care > 0 and care < 300 and bunny.get_life() and !mode)
		{
			ad.setString("BE CAREFUL");
			ad.setPosition(view.getCenter().x - 200, view.getCenter().y - 30);
			window.draw(ad);
			care++;
		}
		else if (care == 10)
		{
			care = 0;
			gone = true;
		}
		else gone = true;
		//если перешел на другой уровень, то победная музыка
		if (bunny.get_win() and !end)
			winable.play();
		//если закончил со вторым уровенем, то музыка кончается
		if (end)
		{
			music.stop();
			if (c_win == 0)
			{
				winable.play();
				c_win++;
			}
		}
		//музыка для меню
		if (menu_after.getStatus() == Music::Stopped and end)
		{
			menu_after.openFromFile("back.ogg");
			menu_after.play();
		}
		//текст перехода на следующий уровень или победы
		if (go < 50 and bunny.get_win())
		{
			if (mark == 2 and !end)
			{
				ad.setString("NEXT LEVEL");
				ad.setPosition(view.getCenter().x - 200, view.getCenter().y - 20);
				window.draw(ad);
				go++;

			}
			else if (mark == 2)
			{
				ad.setString("YOU WIN");
				ad.setPosition(view.getCenter().x - 200, view.getCenter().y - 20);
				window.draw(ad);
				go++;
			}
		}
		else
		{//если победил, то карта отрисовывается заново, все персонажи обновляются
			go = 0;
			bunny.get_win() = false;
			if (end)
			{
				mode = true;
				move = false;
				restart_mark(bunny, dog);
				restart_mark(bunny, snake);
				mark = 1;
				for (int i = 0; i < HEIGHT_MAP; i++)
				{
					tile_map_up[i] = temp_up[i];
					tile_map_down[i] = temp_down[i];
				}
				end = false;
			}
		}
		//музыка проигрыша и надпись при проигрыше
		if (adver != 5000 and !bunny.get_life() and !mode)
		{
			if (f_lose.getStatus() == Music::Stopped)
			{
				f_lose.openFromFile("lose.ogg");
				f_lose.play();
			}
			ad.setString("YOU LOSE");
			ad.setPosition(view.getCenter().x - 180, view.getCenter().y - 20);
			window.draw(ad);
		}
		else if (mode)//если же во время движения камеры вышли в главное меню, то выключаем музыку и убираем надпись
		{
			f_lose.stop();
			bunny.get_life() = true;
			bunny.get_health() = 100;
			adver = 0;
			care = 0;
		}
		else adver = 0;
		//отрисовываем зайца и врагов в зависимости от карты
		if (bunny.get_life())
			window.draw(bunny.get_sprite());
		if (mark == 1)
			window.draw(dog.get_sprite());
		else
			window.draw(snake.get_sprite());
		//если вошли в меню
		if (mode)
		{
			music.stop();//останавливаем музыку для бега
			if (menu_after.getStatus() == Music::Stopped)//включаем музыку для меню
			{
				menu_after.openFromFile("back.ogg");
				menu_after.play();
			}
			if (count_carrots > maximum)//выводим лучший результат за сеанс
			{
				maximum = count_carrots;
				r_best = "BEST: ";
				r_best = r_best + std::to_string(maximum);
				best.setString(r_best);
			}
			//надписи
			play.setPosition(view.getCenter().x - 85, view.getCenter().y - 20);
			best.setPosition(view.getCenter().x - 85, view.getCenter().y - 60);
			window.draw(play);
			window.draw(best);
			//результат за прохождение
			if (count_carrots != 0)
			{
				acc.setString(std::to_string(count_carrots));
				acc.setPosition(view.getCenter().x - 20, view.getCenter().y + 50);
				window.draw(acc);
			}
		}
		if (!mode)//если вне меню, то отрисовываем enter и останавливаем музыку для меню 
		{
			enter.setPosition(view.getCenter().x - 320, view.getCenter().y + 200);
			window.draw(enter);
			menu_after.stop();
		}
		window.display();
	}
	return 0;
}

void view_object_cord(Person& object)//камера следит за персонажем
{
	if (object.get_life())
		view.setCenter(object.get_x(), object.get_y() - 145);
}

void restart(Person& object, Enemy& enemy)//рестарт врага и игрока
{
	object.get_x() = object.start_x;
	object.get_y() = object.start_y;
	object.get_ground() = true;
	object.get_ax() = object.get_ay() = 0;
	object.get_speed() = 0;
	object.get_sprite().setPosition(object.start_x, object.start_y);
	enemy.get_x() = enemy.start_x;
	enemy.get_y() = enemy.start_y;
	enemy.get_sprite().setPosition(enemy.start_x, enemy.start_y);
	enemy.get_ground() = true;
	enemy.get_ax() = -0.05;
	enemy.get_ay() = 0;
	enemy.get_speed() = 0;
}
//конструктор игрока
Person::Person(std::string f, double xex, double yex, double wid, double hei) :file(f), x(xex), y(yex), width(wid), height(hei)
{
	start_x = xex;
	start_y = yex;
	life = true;
	health = 100;
	win = false;
	on_ground = true;
	ax = ay = 0;
	speed = 0;
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, wid, hei));
	sprite.setPosition(x, y);
}
//отвечает за движение игрока, false при отсутствии столкновения с картой
bool Person::update(float time)
{
	x += ax * time;
	if (collision(0))
		return true;
	if (!on_ground)
		ay += 0.0005 * time;
	y += ay * time;
	on_ground = false;
	if (collision(1))
		return true;
	sprite.setPosition(x, y);
	ax = 0;
	return false;
}
//столкновения с картой
bool Person::collision(int dir)
{
	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j < (x + width) / 32; j++)
		{
			if (mark == 1)//первая карта
			{
				if (tile_map_up[i][j] == 'g')//с землей никак нельзя взаимодействовать, можно только стоять
				{
					if (ax > 0 and dir == 0)
						x = j * 32 - width;
					if (ax < 0 and dir == 0)
						x = j * 32 + 32;
					if (ay > 0 and dir == 1)
					{
						y = i * 32 - height;
						ay = 0;
						on_ground = true;//на земле - можно прыгать и двигаться 
					}
					if (ay < 0 and dir == 1)
					{
						y = i * 32 + 32;
						ay = 0;
					}
				}
				if (tile_map_up[i][j] == 'b')//куст аналогичен земле по свойствам
				{
					if (ax > 0 and dir == 0)
						x = j * 32 - width;
					if (ax < 0 and dir == 0)
						x = j * 32 + 32;
					if (ay > 0 and dir == 1)
					{
						y = i * 32 - height;
						ay = 0;
						on_ground = true;
					}
					if (ay < 0 and dir == 1)
					{
						y = i * 32 + 32;
						ay = 0;
					}
				}
				if (tile_map_up[i][j] == 'h')//падаем в яму
				{
					if (ax > 0 and dir == 0)
						x = j * 32 - width;
					if (ax < 0 and dir == 0)
						x = j * 32 + 32;
					if (ay > 0 and dir == 1)
					{
						y = i * 32 - height;
						ay = 0;
					}
					if (ay < 0 and dir == 1)
					{
						y = i * 32 + 32;
						ay = 0;
					}
					if (int(y / 32) == int(start_y / 32) - 1 and !win)//если упали в яму 
					{//координаты персонажа по у равны его координатам на старте
						x = start_x;
						y = start_y;
						ax = ay = speed = 0;
						sprite.setPosition(x, y);
						health -= 20;
						if (health == 0)
							life = false;
						care = 1;
						return true;//упали в яму
					}
				}
				if (tile_map_up[i][j] == 'w')//столкновение с границами карты, отталкиваемся от них
				{
					if (ax > 0 and dir == 0)
						x = j * 32 - width;
					if (ax < 0 and dir == 0)
						x = j * 32 + 32;
					if (ay > 0 and dir == 1)
					{
						y = i * 32 - height;
						ay = 0;
					}
					if (ay < 0 and dir == 1)
					{
						y = i * 32 + 32;
						ay = 0;
					}
				}
				if (tile_map_up[i][j] == 'c')//съедаем морковку, этот элемент карты исчезает
				{
					tile_map_up[i][j] = ' ';
					count_carrots++;
				}
				if (tile_map_up[i][j] == 's')//съедаем вишню, отнимается здоровье и элемент карты исчезает
				{
					tile_map_up[i][j] = ' ';
					health -= 20;
					if (health == 0)
						life = false;
				}
				if (tile_map_up[i][j] == 'v')//край карты, где происходит перемещение на второй уровень. свойства аналогичны земле и кусту. 
				{
					if (ax > 0 and dir == 0)
						x = j * 32 - width;
					if (ax < 0 and dir == 0)
						x = j * 32 + 32;
					if (ay > 0 and dir == 1)
					{
						y = i * 32 - height;
						ay = 0;
					}
					if (ay < 0 and dir == 1)
					{
						y = i * 32 + 32;
						ay = 0;
					}
					win = true;//победили на уровне
					mark = 2;//перемещение на вторую карту
				}
			}
			else
			{
			if (tile_map_down[i][j] == 'g')//земля
			{
				if (ax > 0 and dir == 0)
					x = j * 32 - width;
				if (ax < 0 and dir == 0)
					x = j * 32 + 32;
				if (ay > 0 and dir == 1)
				{
					y = i * 32 - height;
					ay = 0;
					on_ground = true;
				}
				if (ay < 0 and dir == 1)
				{
					y = i * 32 + 32;
					ay = 0;
				}
			}
			if (tile_map_down[i][j] == 'b')//кирпичи
			{
				if (ax > 0 and dir == 0)
					x = j * 32 - width;
				if (ax < 0 and dir == 0)
					x = j * 32 + 32;
				if (ay > 0 and dir == 1)
				{
					y = i * 32 - height;
					ay = 0;
					on_ground = true;
				}
				if (ay < 0 and dir == 1)
				{
					y = i * 32 + 32;
					ay = 0;
				}
			}
			if (tile_map_down[i][j] == 'w')//границы
			{
				if (ax > 0 and dir == 0)
					x = j * 32 - width;
				if (ax < 0 and dir == 0)
					x = j * 32 + 32;
				if (ay > 0 and dir == 1)
				{
					y = i * 32 - height;
					ay = 0;
				}
				if (ay < 0 and dir == 1)
				{
					y = i * 32 + 32;
					ay = 0;
				}
			}
			if (tile_map_down[i][j] == 'o')//исчезающие блоки
			{
				tile_map_down[i][j] = ' ';//собственно исчезновение с карты
				if (ax > 0 and dir == 0)
					x = j * 32 - width;
				if (ax < 0 and dir == 0)
					x = j * 32 + 32;
				if (ay > 0 and dir == 1)
				{
					y = i * 32 - height;
					ay = 0;
				}
				if (ay < 0 and dir == 1)
				{
					y = i * 32 + 32;
					ay = 0;
				}
			}
			if (tile_map_down[i][j] == 'c')//кукуруза
			{
				tile_map_down[i][j] = ' ';
				count_carrots++;
			}
			if (tile_map_down[i][j] == 'v')//победа
			{
				if (ax > 0 and dir == 0)
					x = j * 32 - width;
				if (ax < 0 and dir == 0)
					x = j * 32 + 32;
				if (ay > 0 and dir == 1)
				{
					y = i * 32 - height;
					ay = 0;
				}
				if (ay < 0 and dir == 1)
				{
					y = i * 32 + 32;
					ay = 0;
				}
				win = true;
				end = true;//закончили карту
			}
			}
		}
		return false;//при отсутствии падения в яму на первой карте
}
//констуктор врага
Enemy::Enemy(std::string f, double xex, double yex, double wid, double hei) :Person(f, xex, yex, wid, hei)
{
	start_x = xex;
	start_y = yex;
	life = true;
	health = 100;
	on_ground = true;
	ax = -0.05;
	ay = 0;
	speed = 0;
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, wid, hei));
	sprite.setPosition(x, y);
}
//движение собаки
void Enemy::update_dog(float time)
{
	if (life)
	{
		x += ax * time;
		collision();
		if (ax > 0)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 0, 50, 40));
		}
		else if (ax < 0)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			sprite.setTextureRect(IntRect(50 * int(CurrentFrame), 40, 50, 40));
		}
		sprite.setPosition(x, y);
	}
}
//движение змеи
void Enemy::update_snake(float time)
{
	if (life)
	{
		x += ax * time;
		collision();
		CurrentFrame += 0.0008 * time;
		if (CurrentFrame > 4) CurrentFrame -= 4;
		sprite.setTextureRect(IntRect(60 * int(CurrentFrame), 0, 60, 60));
		sprite.setPosition(x, y);
	}
}
//столкновение врага с картой
bool Enemy::collision(int dir)
{
	for (int i = y / 32; i < (y + height) / 32; i++)
		for (int j = x / 32; j < (x + width) / 32; j++)
		{
			if (mark == 1)
			{
				if (tile_map_up[i][j] == 'b' or tile_map_up[i][j] == 'w')
				{
					if (ax > 0)
					{
						x = j * 32 - width;
						ax *= -1;//при столкновении меняем направление движения
					}
					else if (ax < 0)
					{
						x = j * 32 + 32;
						ax *= -1;
					}
				}
			}
			else
			{
				if (tile_map_down[i][j] == 'b' or tile_map_down[i][j] == 'w')
				{
					if (ax > 0)
					{
						x = j * 32 - width;
						ax *= -1;
					}
					else if (ax < 0)
					{
						x = j * 32 + 32;
						ax *= -1;
					}
				}
			}
		}
	return false;
}
//рестарт при смене карты
void restart_mark(Person& object, Enemy& enemy)
{
	object.get_x() = object.start_x;
	object.get_y() = 64;
	object.get_ground() = true;
	object.get_ax() = object.get_ay() = 0;
	object.get_speed() = 0;
	object.get_sprite().setPosition(object.start_x, 64);
	enemy.get_x() = enemy.start_x;
	enemy.get_y() = enemy.start_y;
	enemy.get_sprite().setPosition(enemy.start_x, enemy.start_y);
	enemy.get_ground() = true;
	enemy.get_ax() = -0.05;
	enemy.get_ay() = 0;
	enemy.get_speed() = 0;
}
//столкновение игрока с врагом
bool Enemy::crash(Person& player)
{
	if (player.get_life())//если игрок жив 
	{
		if (int(player.get_x()) == int(x))//и координаты по x игрока с врагом совпадают
		{
			if (int(player.get_y() + player.get_height()) / 32 == int(y + height) / 32)
			{//и y на нижнем уровне(из-за высоты спрайта кролика) совпадают
				player.get_health() -= 20;//отнимаем жизни у кролика
				restart(player, *this);//рестартим
				care = 1;//выводим объявление
				gone = false;//небольшой запрет на перемещение
				if (player.get_health() <= 0)
				{
					player.get_life() = false;
					player.get_health() = 0;
				}
				return true;//столкновение произошло
			}
		}
	}
	return false;//столкновения не было
}
