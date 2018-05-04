using Base.Dates.datetime2unix

data, header = readdlm(ARGS[1], '\t', AbstractString, '\n', header=true)

zerodate = datetime2unix(DateTime())
dates = map(x -> DateTime(x, "mm-dd"), data[:, 1])
dates = (map(datetime2unix, dates) - zerodate) / 3600 / 24
dates = reshape(dates, length(dates), 1)
times = map(x -> DateTime(x, "HH-MM"), data[:, 2:3])
times = map(datetime2unix, times) - zerodate
sunrise = times[:, 1:1]
sunset = times[:, 2:2]

X = hcat(ones(length(dates)), dates, dates.^2)
a1 = (X' * X) \ X' * sunrise
a2 = (X' * X) \ X' * sunset
writedlm(string(ARGS[1], "_out"), vcat(a1, a2))

# input as days and output as seconds for sunrise and sunset
