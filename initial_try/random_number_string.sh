# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_number_string.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 01:28:59 by akuburas          #+#    #+#              #
#    Updated: 2024/02/16 01:32:20 by akuburas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for i in {1..500}
do
  echo $((RANDOM % 601 - 100))
done | paste -sd " " -