def largestRectangleArea(h):
    maxArea=0
    n=len(h)
    for i in range(n):
        minHeight=h[i]
        for j in range(i,n):
            minHeight=min(minHeight,h[j]) #Minimum height
            width=j-i+1
            area=minHeight*width
            maxArea=max(maxArea,area)#Update maximum
    print("Largest Rectangle Area is:")
    return maxArea
print(largestRectangleArea([2, 1, 5, 6, 2, 3]))