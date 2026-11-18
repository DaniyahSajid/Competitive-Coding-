def largestRectangleArea(h):
    h.append(0)#Sentinal bar
    stack=[]#Monotonic stack
    maxArea=0 #initially maxArea will be zero
    for i in range(len(h)):
        while stack and h[stack[-1]]>h[i]:
            height=h[stack.pop()]# Pop taller bar
            left=stack[-1] if stack else -1
            width=i-left-1
            maxArea=max(maxArea,height*width)

        stack.append(i)# Store current index
    h.pop()#Remove sentinel
    print("Largest Rectangle Area:")
    return maxArea
print(largestRectangleArea([2, 1, 5, 6, 2, 3]))
