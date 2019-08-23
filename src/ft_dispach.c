#include "../includes/fdf.h"

t_ptr	ft_dispach(char *str)
{
	t_ptr	ptr;
	int	fd;
	char	*line;
	int	i;
	int	mult;
	int	x;
	int	y;

	ptr.h_max = 0;
	ptr.h_min = 0;
	fd = open(str, O_RDONLY);
	ptr.y = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		ptr.x = 0;
		while (line[i] == ' ' || line[i] == '-'
				|| (line[i] > 47 && line[i] < 58))
		{
			if (line[i] == '-' || (line[i] > 47 && line[i] < 58))
			{;
				i++;
				while (line[i] > 47 && line[i] < 58)
					i++;
				i--;
				ptr.x++;
			}
			i++;
		}
		ptr.y++;
	}
	close(fd);
	fd = open(str, O_RDONLY);
	ptr.vector = (t_vector*)malloc(sizeof(t_vector) * (ptr.x * ptr.y + 1));
	ptr.vector[ptr.x * ptr.y].x = -1;
	y = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		x = 0;
		while (line[i] == ' ' || line[i] == '-'
				|| (line[i] > 47 && line[i] < 58))
		{
			if (line[i] == '-' || (line[i] > 47 && line[i] < 58))
			{
				mult = 1;
				i++;
				while (line[i] > 47 && line[i] < 58)
					i++;
				i--;
				ptr.vector[ptr.x * y + x].z = 0;
				while (i >= 0 && line[i] > 47 && line[i] < 58)
				{
					ptr.vector[ptr.x * y + x].z = ptr.vector[ptr.x * y + x].z + (line[i] - 48) * mult;
					mult = mult * 10;
					i--;
				}
				if (i >= 0 && line[i] == '-')
				{
					ptr.vector[ptr.x * y + x].z = -ptr.vector[ptr.x * y + x].z;
					i--;
				}
				i++;
				while (line[i] == '-' || (line[i] > 47 && line[i] < 58))
					i++;
				i--;
				if (ptr.vector[ptr.x * y + x].z > ptr.h_max)
					ptr.h_max = ptr.vector[ptr.x * y + x].z;
				if (ptr.vector[ptr.x * y + x].z < ptr.h_min)
					ptr.h_min = ptr.vector[ptr.x * y + x].z;
				ptr.vector[ptr.x * y + x].x = x;
				ptr.vector[ptr.x * y + x].y = y;
				x++;
			}
			i++;
		}
		y++;
	}
	close(fd);
	return (ptr);
}
