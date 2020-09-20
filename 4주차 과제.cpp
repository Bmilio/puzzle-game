#include <bangtal.h>
#include<iostream>
#include<ctime>
#include <cstdio>
#include <string.h>
#include <sstream>

using namespace bangtal;
using namespace std;

struct ktx
{
    int x = 0;
    int y = 0;
    ObjectPtr z = NULL;
    int a = 0; //원래 있어야 하는 자리
    int b = 0; //지금 있는 자리
};

void swap(ktx* a, ktx* b)
{
    int c, d, e;

    c = (*a).x;
    (*a).x = (*b).x;
    (*b).x = c;

    d = (*a).y;
    (*a).y = (*b).y;
    (*b).y = d;

    e = (*a).b;
    (*a).b = (*b).b;
    (*b).b = e;

    return;
}

bool isNearW(ktx a, ktx w)
{
    if (a.x == w.x && -1 <= a.y - w.y && a.y - w.y <= 1)
        return true;

    if (a.y == w.y && -1 <= a.x - w.x && a.x - w.x <= 1)
        return true;

    return false;
}

int asdf = 0;

int main()
{

    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

    ScenePtr  scene1 = Scene::create("룸1", "images/아이오니아.png");
    ScenePtr  scene2 = Scene::create("룸2", "images/아이오니아2.jpg");
    ScenePtr  yasuo = Scene::create("룸3", "images/야스오.png");
    ScenePtr  irelia = Scene::create("룸4", "images/이렐리아.png");

    auto star = Object::create("images/게임시작.png", scene1, 1280 / 2 - 288 / 2, 720 / 2 - 92 / 2 - 200);
    auto yasuo1 = Object::create("images/야스오.png", scene2, 1280 - (1280 / 2 - 288 / 2), 720 / 2 - 92 / 2 - 100);
    yasuo1->setScale(0.2f);
    auto irelia1 = Object::create("images/이렐리아.png", scene2, 1280 / 2 - 288 / 2 - 300, 720 / 2 - 92 / 2 - 100);
    irelia1->setScale(0.2f);
    auto back1 = Object::create("images/돌아가기.png", yasuo, 50, 50);
    back1->setScale(0.7f);
    auto star1 = Object::create("images/게임시작.png", yasuo, 50, 50 + 92 + 20);
    star1->setScale(0.7f);
    auto end1 = Object::create("images/완료.png", yasuo, 50, 50 + 92 + 100);
    end1->setScale(0.7f);
    auto back2 = Object::create("images/돌아가기.png", irelia, 50, 50);
    back2->setScale(0.7f);
    auto star2 = Object::create("images/게임시작.png", irelia, 50, 50 + 92 + 20);
    star2->setScale(0.7f);
    auto end2 = Object::create("images/완료.png", irelia, 50, 50 + 92 + 100);
    end2->setScale(0.7f);
    auto sco1 = Object::create("images/기록.png", yasuo, 50, 50 + 92 + 100 + 80);
    sco1->setScale(0.7f);
    auto sco2 = Object::create("images/기록.png", irelia, 50, 50 + 92 + 100 + 80);
    sco2->setScale(0.7f);



    yasuo1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        yasuo->enter();
        return 0;
        });
    irelia1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        irelia->enter();
        return 0;
        });
    star->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        scene2->enter();
        return 0;
        });
    back1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        scene2->enter();
        return 0;
        });
    back2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        scene2->enter();
        return 0;
        });

    int score = 0;


    ktx as1[15];
    ktx as2[8];

    //as1 배열 설정
    for (int i = 0; i < 15; i++)
    {
        as1[i].a = i;
        as1[i].b = i;
        as1[i].x = i % 4;
        as1[i].y = i / 4;
    }
    for (int i = 0; i < 8; i++)
    {
        as2[i].a = i;
        as2[i].b = i;
        as2[i].x = i % 3;
        as2[i].y = i / 3;
    }

    ktx w;
    w.a = 15; w.b = 15; w.x = 15 % 4; w.y = 15 / 4;
    ktx w2;
    w2.a = 8; w2.b = 8; w2.x = 8 % 3; w2.y = 8 / 3;

    int k = 0;

    //조각들
    {
        as1[k].z = Object::create("images/야스오 조각/야스오_001.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y); k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_002.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y); k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_003.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y); k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_004.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y); k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_005.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y); k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_006.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_007.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_008.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_009.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_010.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_011.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_012.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_013.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_014.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        as1[k].z = Object::create("images/야스오 조각/야스오_015.jpg", yasuo, 352 + 144 * as1[k].x, 504 - 144 * as1[k].y);    k++;
        w.z = Object::create("images/흰색.png", yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
    }
    {
        k = 0;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_001.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_002.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_003.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_004.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_005.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_006.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_007.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        as2[k].z = Object::create("images/이렐리아 조각/이렐리아_008.png", irelia, 352 + 192 * as2[k].x, 456 - 192 * as2[k].y); k++;
        w2.z = Object::create("images/흰색.png", irelia, 352 + 192 * w2.x, 456 - 192 * w2.y);
        w2.z->setScale(1.33f);
    }

    int t1, t2, t3, t4, t5, t6, ymt = 9999999999, imt = 9999999999;

    int j;

    //시작하기, 다시하기
    bool q1 = false;
    bool q2 = false;
    star1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        for (int i = 0; i < 500; i++)
        {
            j = rand() % 15;

            if (isNearW(as1[j], w))
            {
                swap(&as1[j], &w);
                as1[j].z->locate(yasuo, 352 + 144 * as1[j].x, 504 - 144 * as1[j].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
        }
        q1 = true;
        star1->setImage("images/다시하기.png");
        t1 = time(0);
        return 0;
        });
    star2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        for (int i = 0; i < 300; i++)
        {
            j = rand() % 8;
            if (isNearW(as2[j], w2))
            {
                swap(&as2[j], &w2);
                as2[j].z->locate(irelia, 352 + 192 * as2[j].x, 456 - 192 * as2[j].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 456 - 192 * w2.y);
            }
        }
        q2 = true;
        star2->setImage("images/다시하기.png");
        t5 = time(0);
        return 0;
        });

    //블록 움직이는 코드
    {
        as1[0].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 0;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[1].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 1;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[2].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 2;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[3].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 3;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[4].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 4;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[5].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 5;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[6].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 6;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[7].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 7;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[8].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 8;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[9].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 9;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[10].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 10;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[11].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 11;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[12].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 12;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[13].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 13;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
        as1[14].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 14;
            if (isNearW(as1[i], w))
            {
                swap(&as1[i], &w);
                as1[i].z->locate(yasuo, 352 + 144 * as1[i].x, 504 - 144 * as1[i].y);
                w.z->locate(yasuo, 352 + 144 * w.x, 504 - 144 * w.y);
            }
            return 0;
            });
    }

    {
        as2[0].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 0;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 456 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 456 - 192 * w2.y);
            }
            return 0;
            });
        as2[1].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 1;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 456 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 456 - 192 * w2.y);
            }
            return 0;
            });
        as2[2].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 2;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
        as2[3].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 3;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
        as2[4].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 4;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
        as2[5].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 5;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
        as2[6].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 6;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
        as2[7].z->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            int i = 7;
            if (isNearW(as2[i], w2))
            {
                swap(&as2[i], &w2);
                as2[i].z->locate(irelia, 352 + 192 * as2[i].x, 504 - 48 - 192 * as2[i].y);
                w2.z->locate(irelia, 352 + 192 * w2.x, 504 - 48 - 192 * w2.y);
            }
            return 0;
            });
    }
    //끝나는
    end1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        for (int p = 0; p < 15; p++)
            if (as1[p].a != as1[p].b)
            {
                showMessage("멍청한 덴 약도 없지");
                return 0;
            }

        if (q1)
        {
            t2 = time(0);

            t3 = t2 - t1;

            if (t3 <= ymt)
            {
                showMessage(" 신기록입니다!! ");
                ymt = t3;
            }
            else
                showMessage("축하합니다");
        }
        else
            showMessage("멍청한 덴 약도 없지");
        return 0;
        });
    end2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        for (int p = 0; p < 8; p++)
            if (as2[p].a != as2[p].b)
            {
                showMessage("한 놈도 살려두지 마라!");
                return 0;
            }

        if (q2)
        {
            t6 = time(0);

            t4 = t6 - t5;

            if (t4 <= imt)
            {
                showMessage(" 신기록입니다!! ");
                imt = t4;
            }
            else
                showMessage("축하합니다");
        }
        else
            showMessage("한 놈도 살려두지 마라!");
        return 0;
        });

    sco1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        char llps[100];
        sprintf_s(llps, "%d초 입니다.", t3);
        char* const iiii = &llps[0];
        showMessage(iiii);
        llps[0] = NULL;
        return 0;
        });

    sco2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        char llp[100];
        sprintf_s(llp, "%d초 입니다.", t4);
        char* const iii = &llp[0];
        showMessage(iii);
        llp[0] = NULL;
        return 0;
        });


    startGame(scene1);

    return 0;
}