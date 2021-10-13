import sys
import numpy as np
import matplotlib.pyplot as plt

def RightTurn(p1, p2, p3):
	if (p3[1]-p1[1])*(p2[0]-p1[0]) >= (p2[1]-p1[1])*(p3[0]-p1[0]):
		return False
	return True
	
# Chương trình chính
def GrahamScan(P):
	P.sort()			# Sắp xếp các điểm
	L_upper = [P[0], P[1]]		# Khởi tạo mảng Lupper
	# Kiểm tra và tính toán để thu được mảng Lupper 
	for i in range(2,len(P)):
		L_upper.append(P[i])
		while len(L_upper) > 2 and not RightTurn(L_upper[-1],L_upper[-2],L_upper[-3]):
			del L_upper[-2]
	L_lower = [P[-1], P[-2]]	# Khởi tạo mảng Lower
	# Kiểm tra và tính toán để thu được mảng Lower
	for i in range(len(P)-3,-1,-1):
		L_lower.append(P[i])
		while len(L_lower) > 2 and not RightTurn(L_lower[-1],L_lower[-2],L_lower[-3]):
			del L_lower[-2]
	del L_lower[0]
	del L_lower[-1]
	L = L_upper + L_lower		# Dãy bao bọc cuối cùng
	return np.array(L)


def main():
	
	try:
		N = int(sys.argv[1])
	except:
		N = int(input("Nhap N: "))
	
	
	P = [(np.random.randint(0,50),np.random.randint(0,50)) for i in range(N)]
	L = GrahamScan(P)
	P = np.array(P)
	
	# Plot the computed Convex Hull:
	plt.figure()
	plt.plot(L[:,0],L[:,1], 'b-', picker=5)
	plt.plot([L[-1,0],L[0,0]],[L[-1,1],L[0,1]], 'b-', picker=5)
	plt.plot(P[:,0],P[:,1],".r")
	plt.axis('off')
	plt.show()


if __name__ == '__main__':
	main()


