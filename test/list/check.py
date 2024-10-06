log = None
with open("listTest4AllocLog.txt", "r") as f:
  log = f.read().split("\n")

#print(len(log))
log_header = log[0]
log_body   = log[1:-1]
#print(len(log_body))

allocs = []
errors = []

mallocNum = 0
freeNum   = 0

for db in log_body:
  func    = db[0:7]
  out_ptr = db[8:24]
  in_ptr  = db[25:41]
  size    = db[42:58]
  num     = db[59:75]
  if func == "MALLOC ":
    allocs.append(out_ptr)
    mallocNum += 1
  elif func == "CALLOC ":
    allocs.append(out_ptr)
  elif func == "REALLOC":
    i = allocs.index(in_ptr)
    if i < 0:
      errors.append(in_ptr)
    else:
      del allocs[i]
      allocs.append(out_ptr)
  elif func == "FREE   ":
    i = allocs.index(in_ptr)
    if i < 0:
      errors.append(in_ptr)
    else:
      del allocs[i]
    freeNum += 1
  #print(allocs)

print(allocs)
print(errors)
print(mallocNum)
print(freeNum)