import math

# khoảng cách giữa các điểm


def lenght(a, b):
    return (math.sqrt(((a[0]-b[0])**2) + ((a[1]-b[1])**2)))

# bruteforce để tìm kiếm nửa sai lệch ngắn nhất.


def halves_search(a, p, q, m):
    # nếu mảng bao gồm hai điểm =>tìm thấy khoảng cách và so sánh nó với điểm gần nhất
    if len(a) == 2:
        dist = lenght(a[0], a[1])
        if dist < m:
            p, q = a[0], a[1]
            m = dist
    # nếu mảng nhiều hơn 2 => tìm khoảng cách giữa tất cả và so sánh chúng với cái ngắn nhất
    else:
        for x in range(0, len(a)-1):
            for y in range(x+1, len(a)):
                if m > lenght(a[x], a[y]):
                    m = lenght(a[x], a[y])
                    p, q = a[x], a[y]
    return p, q, m

# tìm khoảng cách ngắn nhất của mảng a với p,q là 2 điểm, m là khoảng cách ngắn nhất


def search_pair(a, p, q, m):
    l = len(a)  # lưu độ dài của mảng a
    if l <= (3):
        # nếu length <=3 sử dụng thuật toán brute force
        return (halves_search(a, p, q, m))

    # tìm vị trí giữa mảng và chia thành 2 mảng con có kích thước gần bằng nhau
    midl = l//2
    midx = a[midl][0]
    L = a[:midl]
    R = a[midl:]

    # tìm điểm và tiếp tục chia nhỏ mảng
    p, q, m = search_pair(L, p, q, m)
    p, q, m = search_pair(R, p, q, m)
    p, q, m = get_strip(a, midx, p, q, m)

    # trả về kết quả là 2 điểm tạo nên khoảng cách ngắn nhất và khoảng cách ngắn nhất
    return (p, q, m)


# nhận mảng để đếm
def get_strip(a, xcoordinate, p, q, m):
    # khởi tạo một mảng rổng
    strip = []
    right, left = xcoordinate+int(m), xcoordinate-int(m)
    # tìm các điểm phù hợp sao cho k đi quá điểm x
    for x in a:
        if x[0] > right:
            break
        elif left <= x[0] <= right:
            strip.append(x)
    # sắp xếp các điểm theo theo toạ độ x
    strip.sort(key=lambda x: x[1])
    # kiểm tra khoảng cách trong strip và so sánh khoảng cách ngắn nhất.
    for x in range(0, len(strip)):
        for y in range(x+1, len(strip)):
            dist = lenght(strip[x], strip[y])
            if dist < m:
                p, q = strip[x], strip[y]
                m = dist
    return (p, q, m)


# main function/program
points = [(1, 2), (2, 3), (4, 5)]
points.sort()  # sắp xếp
p, q = points[0], points[1]  # khởi tạo 2 điểm p,q là 2 điểm đầu tiên của mảng
# giả sử khoảng cách của 2 điểm đầu tiên là ngắn nhất
m = lenght(points[0], points[1])
pt, pt2, distance = search_pair(points, p, q, m)
print(distance)
print(pt)
print(pt2)
