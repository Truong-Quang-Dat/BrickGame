# BrickGame
- Game Phá vỡ các bức tường gạch với độ khó tăng dần theo từng màn, build với thư viện [SDL 2](https://www.libsdl.org/)


## Mục lục
   1. [Hướng dẫn cài đặt](#hướng-dẫn-cài-đặt) 
   2. [Mô tả chung](#mô-tả-chung)
   3. [Chức năng đã cài đặt](#chức-năng-đã-cài-đặt)
   4. [Kĩ thuật sử dụng](#kĩ-thuật-sử-dụng)
   5. [Hướng phát triển](#hướng-phát-triển)
   6. [Kết luận](#kết-luận)

---
# Nội dung

## Hướng dẫn cài đặt
  Project sử dụng codeblock trên windows
  ### Yêu cầu
  - Cài đặt SDL2, SDL2_image, SDL2_ttf và SDL2_mixer
  ### Tải và chạy game
  Tải project (Download as zip) về máy hoặc dùng git
  ```
  git clone https://github.com/Truong-Quang-Dat/BrickGame
  ```
## Mô tả chung
  Game tập trung vào việc phá vỡ các viên gạch với cách chơi:
  - Người chơi giữ và di chuyển chuột để nhắm mục tiêu
  - Tìm vị trí và góc tốt nhất để đánh tất cả các viên gạch
  - Khi độ bền của viên gạch về 0 thì nó sẽ bị phá hủy
  - Số bóng có thể được tăng thêm bằng cách bắn trúng các hạt màu xanh
  - Không bao giờ để các viên gạch chạm đáy hoặc trò chơi sẽ kết thúc

  Cơ cấu trò chơi là vô tận, số bóng và độ bền của những viên gạch tăng dần theo từng màn và mật độ xuất hiện của viên gạch ngày càng tăng lên

## Chức năng đã cài đặt
  > Demo
  > [link video demo](https://www.youtube.com/watch?v=tUUhsahg2F0)
  - Màn hình đầu của game chứa các chức năng setting, highscore và những quả bóng màu sắc khác nhau có thể thay đổi tùy ý
    - Trong setting người chơi có thể tắt, bật nhạc của game và có thể xóa dữ liệu về bảng xếp hạng highscore
    - Trong highscore lưu danh sách những lượt chơi có điểm số cao nhất
  - Màn hình chính của game là nơi để chơi game với tính điểm số người chơi, ngoài ra người chơi có thể tạm dừng game, chơi lại ván mới, trở về màn hình đầu tiên hoặc tắt bật âm thanh tùy ý
  - Khi những viên gạch chạm đáy trò chơi kết thúc, người chơi có thể lưu lại tên và xem điểm số của mình xếp hạng bao nhiêu

## Kĩ thuật sử dụng
  - Các kĩ thuật sử dụng với SDL2
    - .

## Hướng phát triển
  - Sau này em sẽ phát triển game bằng cách mở rộng khung game để update thêm nhiều tính năng mới giúp game trở nên đa dạng hơn và tạo bảng xếp hạng cho nhiều người chơi từ nhiều máy khác nhau để có thể chơi cùng, cạnh tranh điểm số với bạn bè
  - Hình minh họa
  ![Final](https://user-images.githubusercontent.com/100523403/169688574-8611b10d-33f8-4f25-a07e-4e62af7b4532.png)
  - Về chức năng có lợi cho người chơi:
    - Tạo những đồng xu trong game (Hình 1), những đồng xu có thể giúp người chơi mở khóa những loại bóng mới với nhiều chức năng đa dạng
      - Ví dụ như quả bóng băng sẽ thỉnh thoảng gây hiệu ứng đóng băng 1 viên gạch, nếu như độ bền của viên gạch không về 0 ở lượt chơi đó thì nó sẽ tự động vỡ ở lượt tiếp theo (Hình 2)
      - Quả bóng lửa sẽ thỉnh thoảng gây ra hiệu ứng lan và phá cả những viên gạch xung quanh (Hình 3)
    - Có icon x2 nhân đôi số bóng chỉ ở lượt sau (Hình 1), icon phá các viên gạch cùng 1 hàng (Hình 4)
  - Về các chướng ngại vật:
    - Các viên gạch màu đen hút hết bóng khi chạm nó (Hình 1), viên gạch màu trắng chỉ cản trở những quả bóng (Hình 4), những viên này chỉ biến mất khi nó chạm tới đáy và không gây kết thúc trò chơi
    - Những viên gạch mới có hình dạng tam giác khiến người chơi khó xác định được hướng bóng bay hơn (Hình 2)
    - Với icon -5 sẽ trừ đi 5 quả bóng của người chơi khi chạm nó (Hình 3)

## Kết luận
  > ádsadadas

[Về đầu trang](#brickgame)

  
