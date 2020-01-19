#include <iostream>
#include "DbLinklist.h"

using namespace std;

struct window
{
    int time;
    int volume;

    window(int _time, int _volume) : time(_time), volume(_volume) {}
    window() {}
};

class SlidingWindow
{
public:
    SlidingWindow(DbList<window>& _window_list, int _size) : window_list(_window_list), size(_size) {
    }

    void CalMaxVolumeForTimePoints()
    {
        while (start->prev != nullptr && end->prev != nullptr)
        {
            while (end->data.time - start->data.time <= size)
            {
                start = start->prev;
            }

            if (end->data.time - start->data.time > size)
            {
                start = start->next;
            }

            DbList<window>::Node* current_start = start;
            while (true)
            {
                if (working_queue.Empty() || current_start->data.volume > working_queue.last->data.volume)
                {
                    working_queue.AppendNode(current_start->data);
                }

                if (current_start == end)
                {
                    break;
                }
                else
                {
                    current_start = current_start->next;
                }
            }

            max_queue.AppendNode(working_queue.last->data); 

            working_queue.Clear();

            if (end != nullptr)
            {
                end = end->prev;
            }
            else
            {
                break;
            }
            
        }
    }
private:
    DbList<window>& window_list;
    DbList<window> working_queue;
    DbList<window> max_queue;
    int size;
    DbList<window>::Node* start = window_list.last;
    DbList<window>::Node* end = window_list.last;
};

int main() {
    DbList<window> list;

    window w1(1, 10);
    window w2(3, 1);
    window w3(5, 4);
    window w4(7, 8);
    window w5(9, 3);
    window w6(12, 9);
    window w7(19, 4);

    list.AppendNode(w1);
    list.AppendNode(w2);
    list.AppendNode(w3);
    list.AppendNode(w4);
    list.AppendNode(w5);
    list.AppendNode(w6);
    list.AppendNode(w7);

    SlidingWindow sliding_win(list, 6);
    sliding_win.CalMaxVolumeForTimePoints();
}
